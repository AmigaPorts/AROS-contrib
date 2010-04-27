#include <exec/types.h>
#include <proto/exec.h>
#include <string.h>
#include "tblib.h"
#include "SDI_compiler.h"

#if defined(__amigaos4__) || defined(__MORPHOS__) || defined(__AROS__)
/* /// "_vsprintf()" */
void _vsprintf( STRPTR buffer,
                CONST_STRPTR fmt,
                VA_LIST args )
{
#ifdef __AROS__
    VNewRawDoFmt(fmt, (VOID (*)())NULL, (APTR)buffer, args);
#else
    RawDoFmt(fmt, (APTR)args, (VOID (*)())NULL, (APTR)buffer);
#endif
}
/* \\\ */

/* /// "_sprintf()" */
void VARARGS68K STDARGS _sprintf( STRPTR buffer,
                                  CONST_STRPTR fmt,... )
{
    VA_LIST args;

    VA_START(args, fmt);
#ifdef NO_LINEAR_VARARGS
    VNewRawDoFmt(fmt, (VOID (*)())NULL, (APTR)buffer, args);
#else
    RawDoFmt(fmt, VA_ARG(args, APTR), (VOID (*)())NULL, (APTR)buffer);
#endif
    VA_END(args);
}
/* \\\ */
#else
/* /// "putchar()" */
static void ASM _putchar( REG(d0, UBYTE c),
                          REG(a3, UBYTE *str) )
{
    // move.b d0,(a3)+
    __emit(0x16c0);
}
/* \\\ */

/* /// "_vsprintf()" */
void _vsprintf( STRPTR buffer,
                CONST_STRPTR fmt,
                VA_LIST args )
{
    RawDoFmt(fmt, (APTR)args, (VOID (*)())_putchar, (APTR)buffer);
}
/* \\\ */

/* /// "_sprintf()" */
void VARARGS68K STDARGS _sprintf( STRPTR buffer,
                                  CONST_STRPTR fmt,... )
{
    VA_LIST args;

    VA_START(args, fmt);
    RawDoFmt(fmt, VA_ARG(args, APTR), (VOID (*)())_putchar, (APTR)buffer);
    VA_END(args);
}
/* \\\ */
#endif

