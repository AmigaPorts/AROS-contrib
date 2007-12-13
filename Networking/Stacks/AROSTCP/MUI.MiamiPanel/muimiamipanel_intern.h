/*
    Copyright � 2002, The AROS Development Team. 
    All rights reserved.
    
    $Id: miamipanel_intern.h 15644 2002-10-30 17:36:30Z stegerg $
*/

#ifndef _MIAMIPANEL_INTERN_H
#define _MIAMIPANEL_INTERN_H

#ifndef EXEC_TYPES_H
#   include <exec/types.h>
#endif
#ifndef EXEC_LIBRARIES_H
#   include <exec/libraries.h>
#endif
#ifndef EXEC_MEMORY_H
#   include <exec/memory.h>
#endif
#ifndef UTILITY_UTILITY_H
#   include <utility/utility.h>
#endif

#include <libraries/mui.h>

#define DEBUG 0
#include <aros/debug.h>

#include "muimiamipanel.h"

/****************************************************************************************/

extern struct TagItem scales[];

struct MiamiPanelBase_intern
{
    struct Library		                 mpb_library;
    struct ExecBase		             *mpb_sysbase;
    BPTR			                             mpb_seglist;

    struct Library		                 *mpb_DOSBase;
    struct Library		                 *mpb_GfxBase;
    struct Library		                 *mpb_UtilityBase;
    struct Library		                 *mpb_IntuitionBase;
    struct Library		                 *mpb_MUIMasterBase;
    struct Library		                 *mpb_IconBase;
    struct Library		                 *mpb_IFFParseBase;
    struct Library		                 *mpb_LocaleBase;
	
	struct SignalSemaphore       mpb_libSem;
	struct SignalSemaphore       mpb_procSem;
	struct SignalSemaphore       mpb_memSem;
	APTR                                      mpb_pool;
	ULONG                                  mpb_flags;
	ULONG                                  mpb_use;

	struct Catalog                      *mpb_cat;

	struct MsgPort                     *mpb_port;
	APTR                                     mpb_app;
	MiamiPanelCallBackType        *mpb_synccb;
	MiamiPanelCallBackType        *mpb_asynccb;

	UBYTE                                  mpb_groupSep[16];
	UBYTE                                  mpb_decPoint[16];

	struct MinList                      mpb_msgList;
	ULONG                                 mpb_freeMsg;

	struct MUI_CustomClass      *mpb_appClass;
	struct MUI_CustomClass      *mpb_aboutClass;
	struct MUI_CustomClass      *mpb_prefsClass;
	struct MUI_CustomClass      *mpb_mgroupClass;
	struct MUI_CustomClass      *mpb_ifGroupClass;
	struct MUI_CustomClass      *mpb_ifClass;
	struct MUI_CustomClass      *mpb_lbuttonClass;
	struct MUI_CustomClass      *mpb_rateClass;
	struct MUI_CustomClass      *mpb_trafficClass;
	struct MUI_CustomClass      *mpb_timeTextClass;
};

enum
{
    BASEFLG_Init = 1<<0,
};

/****************************************************************************************/

#undef MUIPB
#define MUIPB(b)	((struct MiamiPanelBase_intern *)(b))

//#undef SysBase
//#define SysBase     	(MUIPB(MiamiPanelBaseIntern)->mpb_sysbase)

#undef DOSBase
#define DOSBase     	(MUIPB(MiamiPanelBaseIntern)->mpb_DOSBase)
#undef GfxBase
#define GfxBase     	(MUIPB(MiamiPanelBaseIntern)->mpb_GfxBase)
#undef UtilityBase
#define UtilityBase     	(MUIPB(MiamiPanelBaseIntern)->mpb_UtilityBase)
#undef IntuitionBase
#define IntuitionBase     	(MUIPB(MiamiPanelBaseIntern)->mpb_IntuitionBase)
#undef MUIMasterBase
#define MUIMasterBase     	(MUIPB(MiamiPanelBaseIntern)->mpb_MUIMasterBase)
#undef IconBase
#define IconBase     	(MUIPB(MiamiPanelBaseIntern)->mpb_IconBase)
#undef IFFParseBase
#define IFFParseBase     	(MUIPB(MiamiPanelBaseIntern)->mpb_IFFParseBase)
#undef LocaleBase
#define LocaleBase     	(MUIPB(MiamiPanelBaseIntern)->mpb_LocaleBase)

/****************************************************************************************/
#undef MESSAGE
#define MESSAGE(m) ((struct Message *)(m))

#undef PORT
#define PORT(port) ((struct MsgPort *)(port))

#undef INITPORT
#define INITPORT(p,s) (PORT(p)->mp_Flags = PA_SIGNAL, \
                       PORT(p)->mp_SigBit = (UBYTE)(s), \
                       PORT(p)->mp_SigTask = FindTask(NULL), \
                       NewList(&(PORT(p)->mp_MsgList)))

#undef INITMESSAGE
#define INITMESSAGE(m,p,l) (MESSAGE(m)->mn_Node.ln_Type = NT_MESSAGE, \
                            MESSAGE(m)->mn_ReplyPort = PORT(p), \
                            MESSAGE(m)->mn_Length = ((UWORD)l))

/****************************************************************************************/

#endif /* _MIAMIPANEL_INTERN_H */
