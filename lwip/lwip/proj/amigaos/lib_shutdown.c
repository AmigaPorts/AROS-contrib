/*
    Copyright � 2002, The AROS Development Team. 
    All rights reserved.
    
    $Id: lib_shutdown.c,v 1.1 2002/07/11 17:59:24 sebauer Exp $
*/

#include <exec/types.h>

#include "socket_intern.h"
#include "calling.h"

/*****************************************************************************

    NAME */
#ifndef __AROS__
__asm int LIB_shutdown(register __d0 long s, register __d1 long how)
#else
	AROS_LH2(int, LIB_shutdown,

/*  SYNOPSIS */
	AROS_LHA(long, s, D0),
	AROS_LHA(long, how, D1),

/*  LOCATION */
	struct Library *, SocketBase, 84, Socket)
#endif

/*  FUNCTION

    INPUTS

    RESULT

    NOTES

    EXAMPLE

    BUGS
	The function itself is a bug ;-) Remove it!

    SEE ALSO

    INTERNALS

    HISTORY

*****************************************************************************/
{
    AROS_LIBFUNC_INIT
    AROS_LIBBASE_EXT_DECL(struct Library *,SocketBase)

    return -1;

    AROS_LIBFUNC_EXIT

}
