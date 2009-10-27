/**
 * Scout - The Amiga System Monitor
 *
 *------------------------------------------------------------------
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * You must not use this source code to gain profit of any kind!
 *
 *------------------------------------------------------------------
 *
 * @author Andreas Gelhausen
 * @author Richard K�rber <rkoerber@gmx.de>
 */

#include "system_headers.h"

struct PriorityWinData {
    TEXT pwd_Title[WINDOW_TITLE_LENGTH];
    APTR pwd_ParentWindow;
    APTR pwd_PriorityText[2];
    APTR pwd_PriorityString;
    APTR pwd_PrioritySlider;
    APTR pwd_OkButton;
};

STATIC SAVEDS LONG pri_callfunc( struct Hook *hook, Object *obj, STRPTR *contents )
{
    struct PriorityWinData *pwd = INST_DATA(OCLASS(obj), obj);
    STRPTR pristring;
    LONG pri = 0, length;

    pristring = (STRPTR)xget(pwd->pwd_PriorityString, MUIA_String_Contents);

    length = stcd_l(pristring, (LONG *)&pri);
    if (length == strlen(pristring) && pri >= -128 && pri <= 127) {
        set(pwd->pwd_PrioritySlider, MUIA_Slider_Level, pri);
        set(obj, MUIA_Window_ActiveObject, pwd->pwd_OkButton);
    } else {
        set(obj, MUIA_Window_ActiveObject, pwd->pwd_PriorityString);
    }

    return pri;
}
MakeStaticHook(pri_callhook, pri_callfunc);

STATIC ULONG mNew( struct IClass *cl,
                   Object *obj,
                   struct opSet *msg )
{
    APTR pritext1, pritext2, pritext3, SL_Priority, okButton, cancelButton;

    if ((obj = (Object *)DoSuperNew(cl, obj,
        MUIA_Window_ID, MakeID('P','R','I','O'),
        WindowContents, VGroup,

            Child, MyVSpace(2),
            Child, pritext1 = MyTextObject(),
            Child, MyVSpace(2),
            Child, SL_Priority = SliderObject,
                MUIA_Slider_Min, -128,
                MUIA_Slider_Max, 127,
                MUIA_Slider_Level, 0,
                MUIA_FixHeightTxt, " ",
                MUIA_CycleChain, TRUE,
            End,
            Child, MyVSpace(2),
            Child, HGroup, MUIA_Group_SameWidth, TRUE,
                Child, HGroup,
                    Child, MyLabel2(txtMinPri),
                    Child, MyTextObject3(MUIX_C "-128"),
                End,
                Child, HGroup,
                    Child, MyLabel2(txtMaxPri),
                    Child, MyTextObject3(MUIX_C "127"),
                End,
                Child, HGroup,
                    Child, MyLabel2(txtOldPri),
                    Child, pritext2 = MyTextObject(),
                End,
                Child, HGroup,
                    Child, MyLabel2(txtNewPri),
                    Child, pritext3 = StringObject,
                        MUIA_String_BufferPos, 1,
                        MUIA_String_Accept , "-0123456879",
                        MUIA_String_Integer, 0,
                        MUIA_String_MaxLen, 5,
                        MUIA_String_Format, MUIV_String_Format_Right,
                        MUIA_CycleChain, TRUE,
                        StringFrame,
                    End,
                End,
            End,
            Child, MyVSpace(2),
            Child, HGroup, MUIA_Group_SameWidth, TRUE,
                Child, okButton = MakeButton(txtMUIOk),
                Child, cancelButton = MakeButton(txtMUICancel),
            End,
        End,
        TAG_MORE, msg->ops_AttrList)) != NULL)
    {
        struct PriorityWinData *pwd = INST_DATA(cl, obj);

        pwd->pwd_PriorityText[0] = pritext1;
        pwd->pwd_PriorityText[1] = pritext2;
        pwd->pwd_PriorityString = pritext3;
        pwd->pwd_PrioritySlider = SL_Priority;
        pwd->pwd_OkButton = okButton;

        set(obj, MUIA_Window_Title, MyGetWindowTitle(txtPriorityWinTitle, pwd->pwd_Title, sizeof(pwd->pwd_Title)));
        set(obj, MUIA_Window_ActiveObject, SL_Priority);

        DoMethod(AP_Scout,     OM_ADDMEMBER, obj);
        DoMethod(obj,          MUIM_Notify,  MUIA_Window_CloseRequest, TRUE,           MUIV_Notify_Application, 2, MUIM_Application_ReturnID, 1);
        DoMethod(SL_Priority,  MUIM_Notify,  MUIA_Slider_Level,        MUIV_EveryTime, pritext3,                4, MUIM_SetAsString, MUIA_String_Contents, "%ld", MUIV_TriggerValue);
        DoMethod(pritext3,     MUIM_Notify,  MUIA_String_Acknowledge,  MUIV_EveryTime, obj,                     3, MUIM_CallHook, &pri_callhook, MUIV_TriggerValue);
        DoMethod(okButton,     MUIM_Notify,  MUIA_Pressed,             FALSE,          MUIV_Notify_Application, 2, MUIM_Application_ReturnID, 2);
        DoMethod(cancelButton, MUIM_Notify,  MUIA_Pressed,             FALSE,          MUIV_Notify_Application, 2, MUIM_Application_ReturnID, 1);
    }

    return (ULONG)obj;
}

STATIC ULONG mDispose( struct IClass *cl,
                       Object *obj,
                       Msg msg )
{
    set(obj, MUIA_Window_Open, FALSE);

    DoMethod(AP_Scout, OM_REMMEMBER, obj);

    return (DoSuperMethodA(cl, obj, msg));
}

STATIC ULONG mSet( struct IClass *cl,
                   Object *obj,
                   struct opSet *msg )
{
    struct PriorityWinData *pwd = INST_DATA(cl, obj);
    struct TagItem *tags, *tag;

    tags = msg->ops_AttrList;
    while ((tag = NextTagItem(&tags)) != NULL) {
        switch (tag->ti_Tag) {
            case MUIA_PriorityWin_ObjectName:
                MySetContents(pwd->pwd_PriorityText[0], msgSelectNewPriority, (UBYTE *)tag->ti_Data);
                break;

            case MUIA_PriorityWin_Priority:
                set(pwd->pwd_PrioritySlider, MUIA_Slider_Level, tag->ti_Data);
                MySetContents(pwd->pwd_PriorityText[1], MUIX_C "%4ld", tag->ti_Data);
                set(pwd->pwd_PriorityString, MUIA_String_Integer, tag->ti_Data);
                break;
        }
    }

    return DoSuperMethodA(cl, obj, (Msg)msg);
}

STATIC ULONG mGet( struct IClass *cl,
                   Object *obj,
                   struct opGet *msg )
{
    struct PriorityWinData *pwd = INST_DATA(cl, obj);
    ULONG *store = msg->opg_Storage;

    switch (msg->opg_AttrID) {
        case MUIA_PriorityWin_Priority:
            get(pwd->pwd_PrioritySlider, MUIA_Slider_Level, store);
            return TRUE;
    }

    return DoSuperMethodA(cl, obj, (Msg)msg);
}

STATIC ULONG mGetPriority( struct IClass *cl,
                           Object *obj,
                           Msg msg )
{
    BOOL done = FALSE;
    ULONG result = 0;

    set(_app(obj), MUIA_Application_Sleep, TRUE);
    set(obj, MUIA_Window_Open, TRUE);

    while (!done) {
        ULONG signals;

        switch (DoMethod(_app(obj), MUIM_Application_NewInput, &signals)) {
            case MUIV_Application_ReturnID_Quit:
            case 1:
                done = TRUE;
                result = 0;
                break;

            case 2:
                done = TRUE;
                result = 1;

            default:
                break;
        }

        if (!done && signals != 0) {
            Wait(signals);
        }
    }

    set(obj, MUIA_Window_Open, FALSE);
    set(_app(obj), MUIA_Application_Sleep, FALSE);

    return result;
}

DISPATCHER(PriorityWinDispatcher)
{
    switch (msg->MethodID) {
        case OM_NEW:                       return (mNew(cl, obj, (APTR)msg));
        case OM_DISPOSE:                   return (mDispose(cl, obj, (APTR)msg));
        case OM_SET:                       return (mSet(cl, obj, (APTR)msg));
        case OM_GET:                       return (mGet(cl, obj, (APTR)msg));
        case MUIM_PriorityWin_GetPriority: return (mGetPriority(cl, obj, (APTR)msg));
    }

    return DoSuperMethodA(cl, obj, msg);
}
DISPATCHER_END

APTR MakePriorityWinClass( void )
{
    return MUI_CreateCustomClass(NULL, MUIC_Window,  NULL, sizeof(struct PriorityWinData), DISPATCHER_REF(PriorityWinDispatcher));
}
