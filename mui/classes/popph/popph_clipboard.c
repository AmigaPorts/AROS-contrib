
/*
** $Id: popph_clipboard.c,v 1.3 1999/11/25 18:38:56 carlos Exp $
**
** � 1999 Marcin Orlowski <carlos@amiga.com.pl>
*/

#include "popph.h"

/// _WriteClip
int _WriteClip( char *data, int len, int clip_device )
{
struct IFFHandle *iffh;
APTR   cliphandle;
int    rc = FALSE;

    if( iffh = AllocIFF() )
       {
       if( cliphandle = OpenClipboard( clip_device ) )
           {
           iffh->iff_Stream = (ULONG)cliphandle;
           InitIFFasClip( iffh );

           if( !OpenIFF( iffh, IFFF_WRITE ) )
               {
               PushChunk( iffh, MAKE_ID( 'F','T','X','T' ), MAKE_ID( 'F','O','R','M' ), IFFSIZE_UNKNOWN );
               PushChunk( iffh, MAKE_ID( 'F','T','X','T' ), MAKE_ID( 'C','H','R','S' ), IFFSIZE_UNKNOWN );

               WriteChunkBytes( iffh, data, len );

               PopChunk( iffh );
               PopChunk( iffh );

               CloseIFF( iffh );

               rc = TRUE;
               }

           CloseClipboard( cliphandle );
           }

       FreeIFF( iffh );
       }

    return( rc );
}
//|

