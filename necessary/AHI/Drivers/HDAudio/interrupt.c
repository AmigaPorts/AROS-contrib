#include <config.h>

#include <proto/expansion.h>
#include <libraries/ahi_sub.h>
#include <proto/exec.h>
#include <stddef.h>
#include "library.h"
#include "regs.h"
#include "interrupt.h"
#include "misc.h"
#include "pci_wrapper.h"
#ifdef __AROS__
#include <aros/debug.h>
#endif

#define min(a,b) ((a)<(b)?(a):(b))

int z = 0;
ULONG timer = 0; // for demo/test

#define TIME_LIMIT 150 // 150 irq's

/******************************************************************************
** Hardware interrupt handler *************************************************
******************************************************************************/


#ifdef __AMIGAOS4__
ULONG
CardInterrupt( struct ExceptionContext *pContext, struct ExecBase *SysBase, struct CardData* card )
#else
ULONG
CardInterrupt( struct CardData* card )
#endif
{
    struct AHIAudioCtrlDrv* AudioCtrl = card->audioctrl;
    struct DriverBase*  AHIsubBase = (struct DriverBase*) card->ahisubbase;
    struct PCIDevice *dev = (struct PCIDevice *) card->pci_dev;

    ULONG intreq, status;
    LONG  handled = 0;
    UBYTE rirb_status;
    int i;

    intreq = pci_inl(HD_INTSTS, card);

    if (intreq & HD_INTCTL_GLOBAL)
    {       
        if (intreq & 0x01FFFFFFF) // stream interrupt
        {
            ULONG position;
            BOOL playback = FALSE;
            BOOL recording = FALSE;
            
            //bug("Stream irq\n");
            for (i = 0; i < card->nr_of_streams; i++)
            {
                if (intreq & (1 << card->streams[i].index))
                {
                    // acknowledge stream interrupt
                    pci_outb(0x1C, card->streams[i].sd_reg_offset + HD_SD_OFFSET_STATUS, card);

                    if (i < card->nr_of_input_streams)
                    {
                        recording = TRUE;
                    }
                    else
                    {
                        playback = TRUE;
                    }
                }
            }
            
            pci_outb(0xFF, HD_INTSTS, card);

            z++;            
#ifdef TIME_LIMITED            
            timer++;
            
            if (timer > TIME_LIMIT) // stop playback
            {
                outb_clearbits(HD_SD_CONTROL_STREAM_RUN, card->streams[card->nr_of_input_streams].sd_reg_offset + HD_SD_OFFSET_CONTROL, card);
            }
#endif
            
            //bug("SIRQ\n");
            
            if (playback)
            {
              //  bug("PB\n");
                position = pci_inl(card->streams[card->nr_of_input_streams].sd_reg_offset + HD_SD_OFFSET_LINKPOS, card);

                if (card->flip == 1) //position <= card->current_bytesize + 64)
                {
                   if (card->flip == 0)
                   {
                      bug("Lost IRQ!\n");
                   }
                   card->flip = 0;
                   card->current_buffer = card->playback_buffer1;
                }
                else
                {
                   if (card->flip == 1)
                   {
                      bug("Lost IRQ!\n");
                   }
                   
                   card->flip = 1;
                   card->current_buffer = card->playback_buffer2;
                }

                Cause(&card->playback_interrupt);
            }

            if (recording)
            {
                position = pci_inl(card->streams[0].sd_reg_offset + HD_SD_OFFSET_LINKPOS, card);

                if (card->recflip == 1) //position <= card->current_record_bytesize + 64)
                {
                   if (card->recflip == 0)
                   {
                      bug("Lost rec IRQ!\n");
                   }
                   card->recflip = 0;
                   card->current_record_buffer = card->record_buffer1;
                }
                else
                {
                   if (card->recflip == 1)
                   {
                      bug("Lost rec IRQ!\n");
                   }
                   
                   card->recflip = 1;
                   card->current_record_buffer = card->record_buffer2;
                }

                Cause(&card->record_interrupt);
            }
        }
        
        if (intreq & HD_INTCTL_CIE)
        {
            //bug("CIE\n");
            pci_outb(0x4, HD_INTSTS + 3, card); // only byte access allowed
           
  //          if (card->is_playing)
    //            bug("CIE irq! rirb is %x, STATESTS = %x\n", pci_inb(HD_RIRBSTS, card), pci_inw(HD_STATESTS, card));
        
            // check for RIRB status
            rirb_status = pci_inb(HD_RIRBSTS, card);
            if (rirb_status & 0x5)
            {
                if (rirb_status & 0x4) // RIRBOIS
                {
//                    bug("RIRB overrun!\n");
                }
           
                if (rirb_status & 0x1) // RINTFL
                {
                    card->rirb_irq++;
                    
                    /*if (card->rirb_irq > 1)
                    {
                       bug("IRQ: rirb_irq = %d\n", card->rirb_irq);
                    }*/
                    //bug("RIRB IRQ!\n");
                }
           
                pci_outb(0x5, HD_RIRBSTS, card);
            }
        }
        
        handled = 1;
    }

    return handled;
}


/******************************************************************************
** Playback interrupt handler *************************************************
******************************************************************************/

#ifdef __AMIGAOS4__
void
PlaybackInterrupt( struct ExceptionContext *pContext, struct ExecBase *SysBase, struct CardData* card )
#else
void
PlaybackInterrupt( struct CardData* card )
#endif
{
    struct AHIAudioCtrlDrv* AudioCtrl = card->audioctrl;
    struct DriverBase*  AHIsubBase = (struct DriverBase*) card->ahisubbase;

    if (card->mix_buffer != NULL && card->current_buffer != NULL && card->is_playing)
    {
        BOOL   skip_mix;

        WORD*  src;
        int    i;
        LONG* srclong, *dstlong, left, right;
        int frames = card->current_frames;

        skip_mix = CallHookPkt(AudioCtrl->ahiac_PreTimerFunc, (Object*) AudioCtrl, 0);  
        CallHookPkt(AudioCtrl->ahiac_PlayerFunc, (Object*) AudioCtrl, NULL);

        if (! skip_mix)
        {
            CallHookPkt(AudioCtrl->ahiac_MixerFunc, (Object*) AudioCtrl, card->mix_buffer);
        }

        /* Now translate and transfer to the DMA buffer */
        srclong = (LONG*) card->mix_buffer;
        dstlong = (LONG*) card->current_buffer;

        i = frames;

        if (AudioCtrl->ahiac_Flags & AHIACF_HIFI)
        {
            while(i > 0)
            {
                *dstlong++ = *srclong++;
                *dstlong++ = *srclong++;

                --i;
            }
        }
        else
        {
            while(i > 0)
            {
                *dstlong++ = (*srclong & 0xFF00) >> 16; srclong++; // tbd
                *dstlong++ = (*srclong & 0xFF000000) >> 16; srclong++;

                --i;
            }
        }

        CallHookPkt(AudioCtrl->ahiac_PostTimerFunc, (Object*) AudioCtrl, 0);
    }
}


/******************************************************************************
** Record interrupt handler ***************************************************
******************************************************************************/

#ifdef __AMIGAOS4__
void
RecordInterrupt( struct ExceptionContext *pContext, struct ExecBase *SysBase, struct CardData* card )
#else
void
RecordInterrupt( struct CardData* card )
#endif
{
    struct AHIAudioCtrlDrv* AudioCtrl = card->audioctrl;
    struct DriverBase*  AHIsubBase = (struct DriverBase*) card->ahisubbase;
    int i = 0;
    int frames = card->current_record_bytesize / 2;
    
    struct AHIRecordMessage rm =
    {
        AHIST_S16S,
        card->current_record_buffer,
        RECORD_BUFFER_SAMPLES
    };

     WORD *src = card->current_record_buffer;
     WORD* dst = card->current_record_buffer;

#ifdef __AMIGAOS4__
     while( i < frames )
     {
       *dst = ( ( *src & 0x00FF ) << 8 ) | ( ( *src & 0xFF00 ) >> 8 );
   
       ++i;
       ++src;
       ++dst;
     }
#else
     /*while( i < frames )
     {
       *dst = (*src);
   
       ++i;
       ++src;
       ++dst;
     }*/
#endif

    CallHookPkt(AudioCtrl->ahiac_SamplerFunc, (Object*) AudioCtrl, &rm);
}


