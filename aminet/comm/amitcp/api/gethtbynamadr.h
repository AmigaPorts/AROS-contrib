/*
 * gethtbynamadr.h
 *
 * Author: Tomi Ollila <too@cs.hut.fi>
 *
 * 	Copyright (c) 1993 OHT-AmiTCP/IP Group
 * 	        All rights reserved
 *
 * Created: Mon May 31 23:10:36 1993 too
 * Last modified: Mon May 31 23:16:03 1993 too
 *
 * HISTORY
 * $Log$
 * Revision 1.1  2001/12/25 22:21:39  henrik
 * lots of assembler in api/amiga_api.h that needs to be fixed
 * better not do it since my knowledge of assembler i almost zero
 * think one need to change adresses to something like eax,ebx or something?
 *
 * Revision 1.1  1993/06/01  16:35:05  too
 * Initial revision
 *
 *
 */


#ifndef API_GETHTBYNAMADR_H
#define API_GETHTBYNAMADR_H

#ifndef API_AMIGA_API_H 
#include <api/amiga_api.h>
#endif


struct hostent * _gethtbyname(struct SocketBase * libPtr,
			      const char * name);
struct hostent * _gethtbyaddr(struct SocketBase * libPtr,
			      const char * addr, int len, int type);

#endif /* API_GETHTBYNAMADR_H */

