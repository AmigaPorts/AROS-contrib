/*

Copyright (C) 2001-2005 Neil Cafferkey

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston,
MA 02111-1307, USA.

*/

#ifndef DEVICE_H
#define DEVICE_H


#include <exec/types.h>
#include <exec/devices.h>
#include <exec/interrupts.h>
#include <exec/semaphores.h>
#include <devices/sana2.h>
#include <devices/sana2specialstats.h>
#include <devices/timer.h>

#include "wireless.h"
#include "io.h"

#define DEVICE_NAME "prism2.device"
#define VERSION 1
#define REVISION 2
#define DATE "16.6.2005"

#define UTILITY_VERSION 39
#define PROMETHEUS_VERSION 2
#define POWERPCI_VERSION 2
#define EXPANSION_VERSION 50
#define OPENPCI_VERSION 1
#define PCCARD_VERSION 1

#ifndef UPINT
#ifdef __AROS__
typedef IPTR UPINT;
typedef SIPTR PINT;
#else
typedef ULONG UPINT;
typedef LONG PINT;
#endif
#endif

#ifndef REG
#ifdef __mc68000
#define _REG(A, B) B __asm(#A)
#define REG(A, B) _REG(A, B)
#else
#define REG(A, B) B
#endif
#endif

#define _STR(A) #A
#define STR(A) _STR(A)

#ifndef __AROS__
#define USE_HACKS
#endif


struct DevBase
{
   struct Device device;
   APTR seg_list;
   struct ExecBase *sys_base;
   struct UtilityBase *utility_base;
   struct Library *prometheus_base;
   struct Library *powerpci_base;
   struct Library *openpci_base;
   struct Library *pccard_base;
   APTR card_base;
   struct MinList pci_units;
   struct MinList pccard_units;
   struct timerequest timer_request;
#ifdef __amigaos4__
   struct Library *expansion_base;
   struct ExecIFace *i_exec;
   struct UtilityIFace *i_utility;
   struct PCIIFace *i_pci;
   struct TimerIFace *i_timer;
#endif
   VOID (*wrapper_int_code)();
};


enum
{
   WRITE_QUEUE,
   ADOPT_QUEUE,
   EVENT_QUEUE,
   GENERAL_QUEUE,
   REQUEST_QUEUE_COUNT
};

enum
{
   PCI_BUS,
   TMD_BUS,
   PLX_BUS,
   PCCARD_BUS
};

enum
{
   LUCENT_FIRMWARE,
   INTERSIL_FIRMWARE,
   SYMBOL_FIRMWARE,
   AIRONET_FIRMWARE
};

#define IO_WINDOW_SIZE 0x40

#define ETH_ADDRESSSIZE 6
#define ETH_HEADERSIZE 14
#define ETH_SNAPHEADERSIZE 22
#define ETH_MTU 1500
#define ETH_MAXPACKETSIZE ((ETH_HEADERSIZE) + (ETH_MTU))

#define ETH_PACKET_DEST 0
#define ETH_PACKET_SOURCE 6
#define ETH_PACKET_TYPE 12
#define ETH_PACKET_IEEELEN 12
#define ETH_PACKET_SNAPTYPE 20
#define ETH_PACKET_DATA 14

#define STAT_COUNT 3


struct DevUnit
{
   struct MinNode node;
   ULONG index;
   ULONG open_count;
   UWORD flags;
   UWORD bus;
   struct Task *task;
   struct MsgPort *request_ports[REQUEST_QUEUE_COUNT];
   struct DevBase *device;
   APTR card;
   BOOL (*insertion_function)(APTR, struct DevBase *);
   VOID (*removal_function)(APTR, struct DevBase *);
   VOID (*WordsIn)(APTR, ULONG, UWORD *, ULONG);
   VOID (*WordsOut)(APTR, ULONG, const UWORD *, ULONG);
   VOID (*BEWordOut)(APTR, ULONG, UWORD);
   UWORD (*LEWordIn)(APTR, ULONG);
   VOID (*LEWordOut)(APTR, ULONG, UWORD);
   UBYTE *rx_buffer;
   UBYTE *tx_buffer;
   UBYTE ssid[IEEE802_11_MAXIDLEN];
   ULONG card_removed_signal;
   ULONG card_inserted_signal;
   ULONG range_count;
   UBYTE address[ETH_ADDRESSSIZE];
   UBYTE default_address[ETH_ADDRESSSIZE];
   struct MinList openers;
   struct MinList type_trackers;
   struct MinList multicast_ranges;
   struct Interrupt status_int;
   struct Interrupt rx_int;
   struct Interrupt tx_int;
   struct Interrupt info_int;
   struct Sana2DeviceStats stats;
   ULONG special_stats[STAT_COUNT];
   ULONG speed;
   struct SignalSemaphore access_lock;
   UWORD encryption;
   UWORD tx_frame_id;
   UWORD mode;
   UWORD channel;
   UWORD firmware_type;
   UWORD ssid_length;
   UWORD key_no;
   struct WEPKey keys[IEEE802_11_WEPKEYCOUNT];
};


struct Opener
{
   struct MinNode node;
   struct MsgPort read_port;
   BOOL (*rx_function)(REG(a0, APTR), REG(a1, APTR), REG(d0, ULONG));
   BOOL (*tx_function)(REG(a0, APTR), REG(a1, APTR), REG(d0, ULONG));
   UBYTE *(*dma_tx_function)(REG(a0, APTR));
   struct Hook *filter_hook;
   struct MinList initial_stats;
#if defined(__amigaos4__) || defined(__MORPHOS__)
   const VOID *real_rx_function;
   const VOID *real_tx_function;
   const VOID *real_dma_tx_function;
#endif
};


struct TypeStats
{
   struct MinNode node;
   ULONG packet_type;
   struct Sana2PacketTypeStats stats;
};


struct TypeTracker
{
   struct MinNode node;
   ULONG packet_type;
   struct Sana2PacketTypeStats stats;
   ULONG user_count;
};


struct AddressRange
{
   struct MinNode node;
   ULONG add_count;
   ULONG lower_bound_left;
   ULONG upper_bound_left;
   UWORD lower_bound_right;
   UWORD upper_bound_right;
};


/* Unit flags */

#define UNITF_SHARED (1 << 0)
#define UNITF_ONLINE (1 << 1)
#define UNITF_HAVEADAPTER (1 << 3)
#define UNITF_CONFIGURED (1 << 4)
#define UNITF_PROM (1 << 5)
#define UNITF_WASONLINE (1 << 6)   /* card was online at time of removal */
#define UNITF_HASWEP (1 << 7)
#define UNITF_ALLMCAST (1 << 8)


IMPORT const TEXT device_name[];


/* Endianness macros */

#define FlipWord(A) \
   ({ \
      UWORD _FlipWord_A = (A); \
      _FlipWord_A = (_FlipWord_A << 8) | (_FlipWord_A >> 8); \
   })

#define FlipLong(A) \
   ({ \
      ULONG _FlipLong_A = (A); \
      _FlipLong_A = \
         (FlipWord(_FlipLong_A) << 16) | FlipWord(_FlipLong_A >> 16); \
   })

#ifndef __i386__ /* Big endian */

#define BEWord(A) \
   (A)

#define BELong(A) \
   (A)

#define LEWord(A) \
   FlipWord(A)

#define LELong(A) \
   FlipLong(A)

#else

#define BEWord(A) \
   FlipWord(A)

#define BELong(A) \
   FlipLong(A)

#define LEWord(A) \
   (A)

#define LELong(A) \
   (A)

#endif

#define MakeBEWord(A) \
   BEWord(A)

#define MakeBELong(A) \
   BELong(A)

#define MakeLEWord(A) \
   LEWord(A)

#define MakeLELong(A) \
   LELong(A)


/* Library and device bases */

#define SysBase (base->sys_base)
#define CardResource (base->card_base)
#define UtilityBase (base->utility_base)
#define ExpansionBase (base->expansion_base)
#define OpenPciBase (base->openpci_base)
#define PrometheusBase (base->prometheus_base)
#define PowerPCIBase (base->powerpci_base)
#define PCCardBase (base->pccard_base)
#define TimerBase (base->timer_request.tr_node.io_Device)

#ifdef __amigaos4__
#define IExec (base->i_exec)
#define IUtility (base->i_utility)
#define ITimer (base->i_timer)
#endif

#ifndef BASE_REG
#define BASE_REG a6
#endif


#endif
