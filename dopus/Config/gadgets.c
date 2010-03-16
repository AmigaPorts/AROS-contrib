/*

Directory Opus 4
Original GPL release version 4.12
Copyright 1993-2000 Jonathan Potter

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

All users of Directory Opus 4 (including versions distributed
under the GPL) are entitled to upgrade to the latest version of
Directory Opus version 5 at a reduced price. Please see
http://www.gpsoft.com.au for more information.

The release of Directory Opus 4 under the GPL in NO WAY affects
the existing commercial status of Directory Opus 5.

*/

#include "config.h"

char
    *mainmenugads[14],
    *listviewgads[3],
    *listviewgads2[4],
    *operationgads[14],
    *systemgads[14],
    *gadgetgads[11],
    *gadflaglist[17],
    *functypelist[14],

    ftype_funcmap[]={
        FTFUNC_CLICKMCLICK,
        FTFUNC_DOUBLECLICK,
        FTFUNC_MMBCLICK,
        FTFUNC_ANSIREAD,
        FTFUNC_HEXREAD,
        FTFUNC_LOOPPLAY,
        FTFUNC_PLAY,
        FTFUNC_READ,
        FTFUNC_SHOW,
        FTFUNC_AUTOFUNC1,
        FTFUNC_AUTOFUNC2,
        FTFUNC_AUTOFUNC3,
        FTFUNC_AUTOFUNC4},
    *functypestr[6],
    *editfuncgads[6],
    *editfuncgads2[16],
    *editclassgads[10],
    *menugadgets[11],
    *drivegadgets[11],
    *drivegadgets2[5],
    *hotkeysgadgets[11],
    *screengadgets[14],
    *palettegadgets[7],
    *coloursgadgets[16],
    *screenmodegadgets[7],
    *formatgadgets[11], //JRZ: was 10
    *hotkeygadgets[3],
    *arrowgadtxt[4],
    *arrowtypetxt[3],
    *filetypeactiongadgets[11];

struct ConfigGadget
    op_copygadgets[]={
        {CTYPE_MOVE,0,-1,20},
        {CTYPE_TEXT,0,STR_OP_COPY_WHENCOPYING,169,30},
        {CTYPE_GAD,0,STR_OP_COPY_CHECKDEST,196,36,-1,-1,COPY_CHECK,0},
        {CTYPE_GAD,0,STR_OP_COPY_SETARCHIVE,196,49,-1,-1,COPY_ARC,0},
        {CTYPE_TEXT,0,STR_OP_COPY_ALSOCOPY,169,77},
        {CTYPE_GAD,0,STR_OP_COPY_DATESTAMP,247,82,-1,-1,COPY_DATE,0},
        {CTYPE_GAD,0,STR_OP_COPY_BITS,247,95,-1,-1,COPY_PROT,0},
        {CTYPE_GAD,0,STR_OP_COPY_COPYARCHIVE,283,108,-1,-1,COPY_COPYARC,0},
        {CTYPE_GAD,0,STR_OP_COPY_COMMENT,247,121,-1,-1,COPY_NOTE,0},
        {CTYPE_TEXT,0,STR_OP_COPY_IFFILEEXISTS,169,147},
        {CTYPE_RAD,1,STR_OP_COPY_ALWAYSREPLACE,249,152,-1,-1,REPLACE_ALWAYS,15},
        {CTYPE_RAD,1,STR_OP_COPY_NEVERREPLACE,249,162,-1,-1,REPLACE_NEVER,15},
        {CTYPE_RAD,1,STR_OP_COPY_ONLYOLDER,249,172,-1,-1,REPLACE_OLDER,15},
        {CTYPE_RAD,1,STR_OP_COPY_ASKBEFORE,249,182,-1,-1,REPLACE_ASK,15},
        {0,0,-1}},
    op_dategadgets[]={
        {CTYPE_TEXT,0,STR_OP_DATE_DATEFORMAT,169,55},
        {CTYPE_RAD,0,STR_OP_DATE_DDMMMYY,249,61,-1,-1,1,15},
        {CTYPE_RAD,0,STR_OP_DATE_YYMMDD,249,71,-1,-1,2,15},
        {CTYPE_RAD,0,STR_OP_DATE_MMDDYY,249,81,-1,-1,4,15},
        {CTYPE_RAD,0,STR_OP_DATE_DDMMYY,249,91,-1,-1,8,15},
        {CTYPE_TEXT,0,STR_MISC_FLAGS,169,119},
        {CTYPE_GAD,0,STR_OP_DATE_NAMESUB,247,126,-1,-1,16,0},
        {CTYPE_GAD,0,STR_OP_DATE_12HOUR,247,139,-1,-1,32,0},
        {0,0,-1}},
    op_deletegadgets[]={
        {CTYPE_TEXT,0,STR_OP_DEL_ASKBEFORE,169,55},
        {CTYPE_GAD,0,STR_OP_DEL_COMMENCING,247,61,-1,-1,1,0},
        {CTYPE_GAD,0,STR_OP_DEL_DELETEFILES,247,74,-1,-1,2,0},
        {CTYPE_GAD,0,STR_OP_DEL_DELETEDIRS,247,87,-1,-1,4,0},
        {CTYPE_TEXT,0,STR_MISC_FLAGS,169,119},
        {CTYPE_GAD,0,STR_OP_DEL_IGNOREPROT,247,126,-1,-1,8,0},
        {0,0,-1}},
    op_errorgadgets[]={
        {CTYPE_TEXT,0,STR_OP_ERROR_ENABLE,169,81},
        {CTYPE_GAD,0,STR_OP_ERROR_DOSREQ,247,87,-1,-1,1,0},
        {CTYPE_GAD,0,STR_OP_ERROR_OPUSREQ,247,100,-1,-1,2,0},
        {0,0,-1}},
    op_generalgadgets[]={
        {CTYPE_TEXT,0,STR_MISC_FLAGS,-1,-1},
        {CTYPE_GAD,0,STR_OP_GENERAL_DRAG,247,-1,-1,-1,GENERAL_DRAG,0},
        {CTYPE_GAD,0,STR_OP_GENERAL_DISPLAYINFO,247,-1,-1,-1,GENERAL_DISPLAYINFO,0},
        {CTYPE_GAD,0,STR_OP_GENERAL_DOUBLECLICK,247,-1,-1,-1,GENERAL_DOUBLECLICK,0},
        {CTYPE_GAD,0,STR_OP_GENERAL_SLIDERACTIVE,247,-1,-1,-1,GENERAL_ACTIVATE,0},
        {CTYPE_GAD,0,STR_OP_GENERAL_FMPARENTMODE,247,-1,-1,-1,GENERAL_FMPARENT,0},
        {CTYPE_GAD,0,STR_OP_GENERAL_FORCEQUIT,247,-1,-1,-1,GENERAL_FORCEQUIT,0},
        {CTYPE_GAD,0,STR_OP_GENERAL_MMBSELECTS,247,-1,-1,-1,GENERAL_MMBSELECTS,0},
        {0,0,-1}},
    op_icongadgets[]={
        {CTYPE_TEXT,0,STR_MISC_FLAGS,169,83},
        {CTYPE_GAD,0,STR_OP_ICON_CREATEWITHDIR,247,90,-1,-1,1,0},
        {CTYPE_GAD,0,STR_OP_ICON_DOUNTOICONS,247,103,-1,-1,2,0},
        {CTYPE_GAD,0,STR_OP_ICON_SELECTAUTO,247,116,-1,-1,4,0},
        {0,0,-1}},
    op_updategadgets[]={
        {CTYPE_TEXT,1,STR_OP_UPDATE_PROGRESS,-1,28 /* HUX: was 38 */},
        {CTYPE_GAD,0,STR_OP_UPDATE_PROGRESSIND,237,-1,-1,-1,32,0},
        {CTYPE_GAD,0,STR_OP_UPDATE_PROGRESSIND_COPY,237,-1,-1,-1,64,0},
        {CTYPE_TEXT,0,-1,-1,-1},
        {CTYPE_TEXT,0,STR_OP_UPDATE_WHENPROCESSING,-1,-1},
        {CTYPE_GAD,0,STR_OP_UPDATE_LEFTJUSTIFY,237,-1,-1,-1,16,0},
        {CTYPE_GAD,0,STR_OP_UPDATE_SCROLLTOFOLLOW,237,-1,-1,-1,2,0},
        {CTYPE_GAD,0,STR_OP_UPDATE_UPDATEFREE,237,-1,-1,-1,1,0},
        {CTYPE_TEXT,0,-1,-1,-1},
        {CTYPE_TEXT,0,STR_MISC_FLAGS,-1,-1},
        {CTYPE_GAD,0,STR_OP_UPDATE_STARTNOTIFY,237,-1,-1,-1,8,0},
        {CTYPE_GAD,0,STR_OP_UPDATE_REDRAWMORE,237,-1,-1,-1,4,0},
        {CTYPE_GAD,0,STR_OP_UPDATE_QUIETGETDIR,237,-1,-1,-1,128,0}, // HUX
        {0,0,-1}},

    *operationgadgets[8]={
        op_copygadgets,op_dategadgets,op_deletegadgets,op_errorgadgets,
        op_generalgadgets,op_icongadgets,NULL,op_updategadgets},

    sys_amigadosgadgets[]={
        {CTYPE_TEXT,0,STR_SYS_AMIGADOS_TITLE,169,75},
        {CTYPE_STR,0,-1,284,84,-1,-1,4,80},
        {CTYPE_REQ,0,STR_SYS_AMIGADOS_SHELL,248,81,-1,-1,0,0,"C:"},
        {CTYPE_STR,0,STR_SYS_AMIGADOS_CONSOLE,252,99,-1,-1,0,80},
        {CTYPE_STR,0,-1,284,114,-1,-1,4,30},
        {CTYPE_REQ,0,STR_SYS_AMIGADOS_STARTUP,248,111,-1,-1,0,0,"S:"},
        {CTYPE_STR,0,STR_SYS_AMIGADOS_PRIORITY,252,129,80,-1,1,3},
        {0,0,-1}},
    sys_clockgadgets[]={
        {CTYPE_TEXT,0,STR_SYS_CLOCK_TITLE,169,26},
        {CTYPE_GAD,0,STR_SYS_CLOCK_MEMORY,227,32,-1,-1,1,0},
        {CTYPE_GAD,0,STR_SYS_CLOCK_CPUMONITOR,227,44,-1,-1,2,0},
        {CTYPE_GAD,0,STR_SYS_CLOCK_DATE,227,56,-1,-1,4,0},
        {CTYPE_GAD,0,STR_SYS_CLOCK_TIME,227,68,-1,-1,8,0},

        {CTYPE_TEXT,0,STR_SYS_CLOCK_SHOWFREEAS,423,26},
        {CTYPE_RAD,0,STR_SYS_CLOCK_BYTES,435,31,-1,-1,64,64},
        {CTYPE_MRAD,0,STR_SYS_CLOCK_KILOBYTES_FREE,435,41,-1,-1,512,576},

        {CTYPE_TEXT,0,STR_SYS_CLOCK_TEXTFORMAT,423,65},
        {CTYPE_MRAD,0,STR_SYS_CLOCK_CHIPANDFAST,435,70,-1,-1,1024,1152},
        {CTYPE_RAD,0,STR_SYS_CLOCK_CANDF,435,80,-1,-1,128,128},
    
        {CTYPE_TEXT,0,STR_SYS_CLOCK_WHENICONIFIED,169,105},
        {CTYPE_MRAD,1,STR_SYS_CLOCK_WINDOW,227,110,-1,-1,256,304},
        {CTYPE_GAD,1,STR_SYS_CLOCK_MEMORY,256,122,-1,-1,1,0},
        {CTYPE_GAD,1,STR_SYS_CLOCK_CPUMONITOR,256,134,-1,-1,2,0},
        {CTYPE_GAD,1,STR_SYS_CLOCK_DATE,256,146,-1,-1,4,0},
        {CTYPE_GAD,1,STR_SYS_CLOCK_TIME,256,158,-1,-1,8,0},
        {CTYPE_RAD,1,STR_SYS_CLOCK_NOWINDOW,227,172,-1,-1,16,48},
        {CTYPE_RAD,1,STR_SYS_CLOCK_APPICON,227,182,-1,-1,32,48},

        {CTYPE_TEXT,0,STR_SYS_CLOCK_SHOWFREEAS,423,116},
        {CTYPE_RAD,1,STR_SYS_CLOCK_BYTES,435,121,-1,-1,64,64},
        {CTYPE_MRAD,1,STR_SYS_CLOCK_KILOBYTES_FREE,435,131,-1,-1,512,576},

        {CTYPE_TEXT,0,STR_SYS_CLOCK_TEXTFORMAT,423,155},
        {CTYPE_MRAD,1,STR_SYS_CLOCK_CHIPANDFAST,435,160,-1,-1,1024,1152},
        {CTYPE_RAD,1,STR_SYS_CLOCK_CANDF,435,170,-1,-1,128,128},
        {0,0,-1}},
    sys_directorygadgets[]={
        {CTYPE_TEXT,0,STR_SYS_DIR_CACHES,160,28},
        {CTYPE_STR,0,STR_SYS_DIR_NUMBUFFERS,341,36,80,-1,1,4},
        {CTYPE_GAD,0,STR_SYS_DIR_ALWAYSEMPTY,189,49,-1,-1,1,0},
        {CTYPE_GAD,0,STR_SYS_DIR_REREADINCOMPLETE,189,62,-1,-1,32,0},

        {CTYPE_TEXT,0,STR_SYS_DIR_SEARCHBUFFERS,160,89},
        {CTYPE_GAD,0,STR_SYS_DIR_SEARCHPARENT,189,94,-1,-1,64,0},
        {CTYPE_GAD,0,STR_SYS_DIR_DIRREAD,189,107,-1,-1,16,0},

        {CTYPE_TEXT,0,STR_MISC_FLAGS,160,136},
        {CTYPE_GAD,0,STR_SYS_DIR_AUTODISKCHANGE,189,142,-1,-1,4,0},
        {CTYPE_GAD,0,STR_SYS_DIR_AUTODISKLOAD,189,155,-1,-1,8,0},
        {CTYPE_GAD,0,STR_SYS_DIR_EXPANDPATHS,189,168,-1,-1,128,0},
        {CTYPE_GAD,0,STR_SYS_DIR_USEEXALL,189,181,-1,-1,2,0},

        {CTYPE_TEXT,0,STR_SYS_CLOCK_SHOWFREEAS,377,148},
        {CTYPE_RAD,1,STR_SYS_CLOCK_BYTES,392,153,-1,-1,1,15},
        {CTYPE_RAD,1,STR_SYS_CLOCK_KILOBYTES,392,163,-1,-1,2,15},
        {CTYPE_RAD,1,STR_SYS_DIR_BLOCKSFREE,392,173,-1,-1,4,15},
        {CTYPE_RAD,1,STR_SYS_DIR_PERCENTAGE,392,183,-1,-1,8,15},
        {0,0,-1}},
    sys_showpatterngadgets[]={
        {CTYPE_TEXT,0,STR_SYS_SHOWPATTERN_TITLE,169,91},
        {CTYPE_GAD,0,STR_SYS_SHOWPATTERN_HIDDENBIT,248,97,-1,-1,1,0},
        {CTYPE_STR,0,STR_SYS_SHOWPATTERN_SHOW,252,112,-1,-1,0,40},
        {CTYPE_STR,0,STR_SYS_SHOWPATTERN_HIDE,252,126,-1,-1,0,40},
        {0,0,-1}},
    sys_startupgadgets[]={
        {CTYPE_TEXT,0,STR_SYS_STARTUP_TITLE,149,60},
        {CTYPE_STR,0,-1,263,69,-1,-1,4,70},
        {CTYPE_REQ,0,STR_SYS_STARTUP_LEFT,227,66,-1,-1,1,0,"SYS:"},
        {CTYPE_STR,0,-1,263,85,-1,-1,4,70},
        {CTYPE_REQ,0,STR_SYS_STARTUP_RIGHT,227,82,-1,-1,1,0,"SYS:"},

        {CTYPE_TEXT,0,STR_SYS_STARTUP_AREXX,149,111},
        {CTYPE_STR,0,-1,263,122,-1,-1,4,80},
        {CTYPE_REQ,0,STR_SYS_STARTUP_STARTUP,227,119,-1,-1,0,0,"REXX:"},
        {CTYPE_STR,0,-1,263,138,-1,-1,4,80},
        {CTYPE_REQ,0,STR_SYS_STARTUP_UNICONIFY,227,135,-1,-1,0,0,"REXX:"},
        {CTYPE_STR,0,-1,263,154,-1,-1,4,80},
        {CTYPE_REQ,0,STR_SYS_STARTUP_CONFIG,227,151,-1,-1,0,0,"REXX:"},
        {0,0,-1}},
    sys_viewplaygadgets[]={
        {CTYPE_TEXT,0,STR_SYS_VIEWPLAY_TITLE,169,22 /* HUX: was 26 */},
        {CTYPE_MOVE,0,-1,27 /* HUX: was 31 */},
        {CTYPE_GAD,0,STR_SYS_VIEWPLAY_BLACK,248,-1,-1,-1,1,0},
        {CTYPE_GAD,0,STR_SYS_VIEWPLAY_PAUSED,248,-1,-1,-1,32,0},
        {CTYPE_GAD,0,STR_SYS_VIEWPLAY_8BITCOL,248,-1,-1,-1,4,0},
        {CTYPE_GAD,0,STR_SYS_VIEWPLAY_BESTMODEID,248,-1,-1,-1,64,0},
        {CTYPE_STR,0,STR_SYS_VIEWPLAY_SHOWDELAY,252,-1,80,-1,1,3},
        {CTYPE_STR,0,STR_SYS_VIEWPLAY_FADEDELAY,462,-2,80,-1,1,3},
        {CTYPE_MOVEREL,0,-1,5 /* HUX: was 8 */},
        {CTYPE_TEXT,0,STR_SYS_VIEWPLAY_SOUNDPLAYER,169,-1},
        {CTYPE_GAD,0,STR_SYS_VIEWPLAY_FILTER,248,-1,-1,-1,2,0},
        {CTYPE_GAD,0,STR_SYS_VIEWPLAY_LOOP,248,-1,-1,-1,8,0},
        {CTYPE_MOVEREL,0,-1,5 /* HUX: was 8 */},
        {CTYPE_TEXT,0,STR_SYS_VIEWPLAY_TEXTVIEW,169,-1},
        {CTYPE_GAD,0,STR_SYS_VIEWPLAY_BORDERS,248,-1,-1,-1,16,0},
        {CTYPE_MOVEREL,0,-1,-13}, //HUX
        {CTYPE_GAD,0,STR_SYS_VIEWPLAY_INWINDOW,448,-1,-1,-1,128,0}, //HUX
        {CTYPE_STR,0,STR_SYS_VIEWPLAY_TABSIZE,252,-1,80,-1,1,3},
        {CTYPE_STR,0,STR_SYS_LEFT_X,452,-2,40,-1,1,7}, // HUX
        {CTYPE_STR,0,STR_SYS_TOP_Y,560,-2,40,-1,1,7},  // HUX
        {CTYPE_STR,0,STR_SYS_WIDTH,452,-1,40,-1,1,7},  // HUX
        {CTYPE_STR,0,STR_SYS_HEIGHT,560,-2,40,-1,1,7}, // HUX
        {0,0,-1}},

    scr_generalgadgets[]={
        {CTYPE_GAD,0,STR_SCREEN_GENERAL_TINYGADS,-1,-1,-1,-1,2,0},
        {CTYPE_GAD,0,STR_SCREEN_GENERAL_GADGETSLIDERS,-1,-1,-1,-1,4,0},
        {CTYPE_GAD,0,STR_SCREEN_GENERAL_WINDOWBORDERS,-1,-1,-1,-1,1,0},
        {CTYPE_GAD,0,STR_SCREEN_GENERAL_TITLEBARSTATUS,-1,-1,-1,-1,128,0},
        {CTYPE_GAD,0,STR_SCREEN_GENERAL_DRAGREQUESTERS,-1,-1,-1,-1,32,0},
        {CTYPE_GAD,0,STR_SCREEN_GENERAL_INDICATERMB,-1,-1,-1,-1,8,0},
//        {CTYPE_GAD,0,STR_SCREEN_GENERAL_NEWLOOKMENUS,-1,-1,-1,-1,64,0},
        {CTYPE_GAD,0,STR_SCREEN_GENERAL_NEWLOOKSLIDERS,-1,-1,-1,-1,16,0},
        {0,0,-1}},

    *systemgadgets[9]={
        sys_amigadosgadgets,sys_clockgadgets,sys_directorygadgets,
        NULL,NULL,NULL,sys_showpatterngadgets,sys_startupgadgets,
        sys_viewplaygadgets};

struct DOpusListView
    editlists[3]={
        {EDIT_FUNCTIONS,NULL,0,0,464,40,NULL,NULL,NULL,DLVF_ENDNL|DLVF_LEAVE|DLVF_HIREC,8,
        0,0,0,0,0,0,0,0,0,0,-1,&editlists[1]},
        {EDIT_FLAGS,NULL,0,0,226,40,NULL,gadflaglist,NULL,
        DLVF_MULTI|DLVF_CHECK|DLVF_SLOW|DLVF_HIREC,8,0,0,0,0,0,0,0,0,0,0,-1,NULL},
        {EDIT_FUNCTIONTYPE,NULL,0,0,272,48,NULL,functypelist,NULL,
        DLVF_SLOW|DLVF_LEAVE|DLVF_HIREC,8,0,0,0,0,0,0,0,0,0,0,-1,NULL}},
    editclasslist={
        1,NULL,0,0,602,48,NULL,NULL,NULL,DLVF_LEAVE|DLVF_ENDNL|DLVF_HIREC,8,
        0,0,0,0,0,0,0,0,0,0,-1,NULL},
    filetypeactionlist={
        2,NULL,0,0,596,120,NULL,NULL,NULL,
        DLVF_LEAVE|DLVF_TTOP|DLVF_HIREC,8,0,0,0,0,0,0,0,0,0,0,-1,NULL},
    hotkeyslist={
        1,NULL,0,0,596,120,NULL,NULL,NULL,
        DLVF_LEAVE|DLVF_TTOP|DLVF_HIREC,8,0,0,0,0,0,0,0,0,0,0,-1,NULL},
    screenmodeview={
        1,NULL,0,0,256,40,NULL,NULL,NULL,
        DLVF_LEAVE|DLVF_SLOW|DLVF_TTOP|DLVF_HIREC,8,0,0,0,0,0,0,0,0,0,0,-1,NULL};

char undobuf[256];

char
    edit_namebuf[256],edit_stackbuf[7],edit_prioritybuf[5],edit_delaybuf[3],
    edit_funcbuf[256],edit_pathbuf[256],edit_actionbuf[40],
    palette_buf[3][4],screenwidth_buf[6],screenheight_buf[6],screendepth_buf[4],
    formatlen_buf[5][8],fontsize_buf[12],edit_typeidbuf[8];

struct StringInfo
    namesinfo={(STRPTR)edit_namebuf,(STRPTR)undobuf,0,0,0,0,0,0,0,0,&stringex},
    stacksinfo={(STRPTR)edit_stackbuf,(STRPTR)undobuf,0,7,0,0,0,0,0,0,&stringex},
    prioritysinfo={(STRPTR)edit_prioritybuf,(STRPTR)undobuf,0,5,0,0,0,0,0,0,&stringex},
    delaysinfo={(STRPTR)edit_delaybuf,(STRPTR)undobuf,0,3,0,0,0,0,0,0,&stringex},
    funcsinfo={(STRPTR)edit_funcbuf,(STRPTR)undobuf,0,256,0,0,0,0,0,0,&stringex},
    pathsinfo={(STRPTR)edit_pathbuf,(STRPTR)undobuf,0,256,0,0,0,0,0,0,&stringex},
    actionsinfo={(STRPTR)edit_actionbuf,(STRPTR)undobuf,0,40,0,0,0,0,0,0,&stringex},
    typeidsinfo={(STRPTR)edit_typeidbuf,(STRPTR)undobuf,0,8,0,0,0,0,0,0,&stringex},
    palettesinfo[3]={
        {(STRPTR)palette_buf[0],(STRPTR)undobuf,0,4,0,0,0,0,0,0,&stringex},
        {(STRPTR)palette_buf[1],(STRPTR)undobuf,0,4,0,0,0,0,0,0,&stringex},
        {(STRPTR)palette_buf[2],(STRPTR)undobuf,0,4,0,0,0,0,0,0,&stringex}},
    screenwidthsinfo={(STRPTR)screenwidth_buf,(STRPTR)undobuf,0,6,0,0,0,0,0,0,&stringex},
    screenheightsinfo={(STRPTR)screenheight_buf,(STRPTR)undobuf,0,6,0,0,0,0,0,0,&stringex},
    screendepthsinfo={(STRPTR)screendepth_buf,(STRPTR)undobuf,0,4,0,0,0,0,0,0,&stringex},
    formatlensinfo[5]={
        {(STRPTR)formatlen_buf[0],(STRPTR)undobuf,0,5,0,0,0,0,0,0,&stringex},
        {(STRPTR)formatlen_buf[1],(STRPTR)undobuf,0,5,0,0,0,0,0,0,&stringex},
        {(STRPTR)formatlen_buf[2],(STRPTR)undobuf,0,5,0,0,0,0,0,0,&stringex},
        {(STRPTR)formatlen_buf[3],(STRPTR)undobuf,0,5,0,0,0,0,0,0,&stringex},
        {(STRPTR)formatlen_buf[4],(STRPTR)undobuf,0,5,0,0,0,0,0,0,&stringex}},
    fontsizesinfo={(STRPTR)fontsize_buf,(STRPTR)undobuf,0,4,0,0,0,0,0,0,&stringex};

struct PropInfo
    menusliderprop={PROPBORDERLESS|FREEVERT,0,0,0,0xffff},
    paletteprop[3]={
        {PROPBORDERLESS|FREEHORIZ,0,0,0xfff,0},
        {PROPBORDERLESS|FREEHORIZ,0,0,0xfff,0},
        {PROPBORDERLESS|FREEHORIZ,0,0,0xfff,0}},
    screenmodeprop/*[3]*/={PROPBORDERLESS|FREEHORIZ,0,0,0x5555,0},
    fileviewprop={PROPBORDERLESS|FREEVERT,0,0,0,0xffff};

struct Image
    menusliderimage={0,0,8,0,1,NULL,0,1,NULL},
    paletteimage[3]={
        {0,0,0,8,1,NULL,0,1,NULL},
        {0,0,0,8,1,NULL,0,1,NULL},
        {0,0,0,8,1,NULL,0,1,NULL}},
    screenmodeimage={0,0,0,8,1,NULL,0,1,NULL},
    fileviewimage={0,0,8,0,1,NULL,0,1,NULL};

struct Gadget
    editfuncgadgets[15]={
        {&editfuncgadgets[1],256,54,140,8,
            GFLG_GADGHCOMP|GFLG_STRINGEXTEND|GFLG_TABCYCLE,GACT_RELVERIFY|GACT_TOGGLESELECT,
            GTYP_STRGADGET,NULL,NULL,NULL,0,(APTR)&namesinfo,EDIT_NAME,NULL},
        {&editfuncgadgets[2],510,66,104,12,
            GFLG_GADGHCOMP,GACT_RELVERIFY|GACT_TOGGLESELECT,
            GTYP_BOOLGADGET,NULL,NULL,NULL,0,NULL,EDIT_SAMPLE,NULL},
        {&editfuncgadgets[3],23,80,104,12,
            GFLG_GADGHCOMP,GACT_RELVERIFY,
            GTYP_BOOLGADGET,NULL,NULL,NULL,0,NULL,EDIT_NEWENTRY,NULL},
        {&editfuncgadgets[4],23,93,104,12,
            GFLG_GADGHCOMP,GACT_RELVERIFY,
            GTYP_BOOLGADGET,NULL,NULL,NULL,0,NULL,EDIT_DUPLICATE,NULL},
        {&editfuncgadgets[5],23,106,104,12,
            GFLG_GADGHCOMP,GACT_RELVERIFY|GACT_TOGGLESELECT,
            GTYP_BOOLGADGET,NULL,NULL,NULL,0,NULL,EDIT_SWAP,NULL},
        {&editfuncgadgets[6],23,119,104,12,
            GFLG_GADGHCOMP,GACT_RELVERIFY,
            GTYP_BOOLGADGET,NULL,NULL,NULL,0,NULL,EDIT_DELETE,NULL},
        {&editfuncgadgets[7],530,142,80,8,
            GFLG_GADGHCOMP|GFLG_STRINGEXTEND|GFLG_TABCYCLE,GACT_RELVERIFY|GACT_TOGGLESELECT|GACT_LONGINT,
            GTYP_STRGADGET,NULL,NULL,NULL,0,(APTR)&stacksinfo,EDIT_STACK,NULL},
        {&editfuncgadgets[8],530,156,80,8,
            GFLG_GADGHCOMP|GFLG_STRINGEXTEND|GFLG_TABCYCLE,GACT_RELVERIFY|GACT_TOGGLESELECT|GACT_LONGINT,
            GTYP_STRGADGET,NULL,NULL,NULL,0,(APTR)&prioritysinfo,EDIT_PRIORITY,NULL},
        {&editfuncgadgets[9],530,170,80,8,
            GFLG_GADGHCOMP|GFLG_STRINGEXTEND|GFLG_TABCYCLE,GACT_RELVERIFY|GACT_TOGGLESELECT|GACT_LONGINT,
            GTYP_STRGADGET,NULL,NULL,NULL,0,(APTR)&delaysinfo,EDIT_DELAY,NULL},
        {&editfuncgadgets[10],130,123,123,14,
            GFLG_GADGHCOMP,GACT_RELVERIFY,
            GTYP_BOOLGADGET,NULL,NULL,NULL,GAD_CYCLE,NULL,EDIT_TYPE,NULL},
        {&editfuncgadgets[11],255,123,28,14,
            GFLG_GADGHCOMP,GACT_RELVERIFY,
            GTYP_BOOLGADGET,NULL,NULL,NULL,0,NULL,EDIT_REQUESTER,NULL},
        {&editfuncgadgets[12],291,126,287,8,
            GFLG_GADGHCOMP|GFLG_STRINGEXTEND|GFLG_TABCYCLE,GACT_RELVERIFY|GACT_TOGGLESELECT,
            GTYP_STRGADGET,NULL,NULL,NULL,1,(APTR)&funcsinfo,EDIT_FUNC,NULL},
        {NULL,586,123,28,14,
            GFLG_GADGHCOMP,GACT_RELVERIFY,
            GTYP_BOOLGADGET,NULL,NULL,NULL,0,NULL,EDIT_ARGREQ,NULL},
        {&editfuncgadgets[14],177,69,433,8,
            GFLG_GADGHCOMP|GFLG_STRINGEXTEND|GFLG_TABCYCLE,GACT_RELVERIFY|GACT_TOGGLESELECT,
            GTYP_STRGADGET,NULL,NULL,NULL,0,(APTR)&actionsinfo,EDIT_FILETYPEACTION,NULL},
        {NULL,486,31,128,14,
            GFLG_GADGHCOMP,GACT_RELVERIFY,
            GTYP_BOOLGADGET,NULL,NULL,NULL,0,NULL,EDIT_EDITCLASS,NULL}},
    editdrivegadgets[4]={
        {&editdrivegadgets[1],248,112,140,8,
            GFLG_GADGHCOMP|GFLG_STRINGEXTEND|GFLG_TABCYCLE,GACT_RELVERIFY|GACT_TOGGLESELECT,
            GTYP_STRGADGET,NULL,NULL,NULL,0,(APTR)&namesinfo,DRIVE_EDITNAME,NULL},
        {&editdrivegadgets[2],488,138,104,12,
            GFLG_GADGHCOMP,GACT_RELVERIFY|GACT_TOGGLESELECT,
            GTYP_BOOLGADGET,NULL,NULL,NULL,0,NULL,DRIVE_EDITSAMPLE,NULL},
        {&editdrivegadgets[3],150,123,28,14,
            GFLG_GADGHCOMP,GACT_RELVERIFY,
            GTYP_BOOLGADGET,NULL,NULL,NULL,0,NULL,DRIVE_EDITREQ,NULL},
        {NULL,186,126,294,8,
            GFLG_GADGHCOMP|GFLG_STRINGEXTEND|GFLG_TABCYCLE,GACT_RELVERIFY|GACT_TOGGLESELECT,
            GTYP_STRGADGET,NULL,NULL,NULL,1,(APTR)&pathsinfo,DRIVE_EDITPATH,NULL}},
    menuslidergads[3]={
        {&menuslidergads[1],616,34,8,142-HIDDENLINES*8,
            GFLG_GADGHNONE,GACT_IMMEDIATE|GACT_FOLLOWMOUSE|GACT_RELVERIFY,
            GTYP_PROPGADGET,(APTR)&menusliderimage,NULL,NULL,0,(APTR)&menusliderprop,MENU_SLIDER,NULL},
        {&menuslidergads[2],612,130,16,8,
            GFLG_GADGHCOMP,GACT_IMMEDIATE|GACT_RELVERIFY,
            GTYP_BOOLGADGET,NULL,NULL,NULL,0,NULL,MENU_MOVEUP,NULL},
        {NULL,612,138,16,8,
            GFLG_GADGHCOMP,GACT_IMMEDIATE|GACT_RELVERIFY,
            GTYP_BOOLGADGET,NULL,NULL,NULL,0,NULL,MENU_MOVEDOWN,NULL}},
    palettegads[6]={
        {&palettegads[1],300,65,216,8,
            GFLG_GADGHNONE,GACT_IMMEDIATE|GACT_FOLLOWMOUSE|GACT_RELVERIFY,
            GTYP_PROPGADGET,(APTR)&paletteimage[0],NULL,NULL,0,(APTR)&paletteprop[0],PALETTE_SLIDER,NULL},
        {&palettegads[2],300,78,216,8,
            GFLG_GADGHNONE,GACT_IMMEDIATE|GACT_FOLLOWMOUSE|GACT_RELVERIFY,
            GTYP_PROPGADGET,(APTR)&paletteimage[1],NULL,NULL,0,(APTR)&paletteprop[1],PALETTE_SLIDER+1,NULL},
        {&palettegads[3],300,91,216,8,
            GFLG_GADGHNONE,GACT_IMMEDIATE|GACT_FOLLOWMOUSE|GACT_RELVERIFY,
            GTYP_PROPGADGET,(APTR)&paletteimage[2],NULL,NULL,0,(APTR)&paletteprop[2],PALETTE_SLIDER+2,NULL},
        {&palettegads[4],254,65,36,8,
            GFLG_GADGHCOMP|GFLG_STRINGEXTEND|GFLG_TABCYCLE,GACT_RELVERIFY|GACT_TOGGLESELECT|GACT_LONGINT|GACT_STRINGRIGHT,
            GTYP_STRGADGET,NULL,NULL,NULL,0,(APTR)&palettesinfo[0],PALETTE_STRING,NULL},
        {&palettegads[5],254,78,36,8,
            GFLG_GADGHCOMP|GFLG_STRINGEXTEND|GFLG_TABCYCLE,GACT_RELVERIFY|GACT_TOGGLESELECT|GACT_LONGINT|GACT_STRINGRIGHT,
            GTYP_STRGADGET,NULL,NULL,NULL,0,(APTR)&palettesinfo[1],PALETTE_STRING+1,NULL},
        {NULL,254,91,36,8,
            GFLG_GADGHCOMP|GFLG_STRINGEXTEND|GFLG_TABCYCLE,GACT_RELVERIFY|GACT_TOGGLESELECT|GACT_LONGINT|GACT_STRINGRIGHT,
            GTYP_STRGADGET,NULL,NULL,NULL,0,(APTR)&palettesinfo[2],PALETTE_STRING+2,NULL}},
    coloursgad={
        NULL,254,16,244,14,
        GFLG_GADGHCOMP,GACT_RELVERIFY,
        GTYP_BOOLGADGET,NULL,NULL,NULL,GAD_CYCLE,NULL,COLOURS_SELECT,NULL},
    screenmodegads[7]={
        {&screenmodegads[1],303,82,58,8,
            GFLG_GADGHCOMP|GFLG_STRINGEXTEND|GFLG_TABCYCLE,GACT_RELVERIFY|GACT_TOGGLESELECT|GACT_LONGINT,
            GTYP_STRGADGET,NULL,NULL,NULL,0,(APTR)&screenwidthsinfo,SCREENMODE_WIDTH,NULL},
        {&screenmodegads[2],303,97,58,8,
            GFLG_GADGHCOMP|GFLG_STRINGEXTEND|GFLG_TABCYCLE,GACT_RELVERIFY|GACT_TOGGLESELECT|GACT_LONGINT,
            GTYP_STRGADGET,NULL,NULL,NULL,0,(APTR)&screenheightsinfo,SCREENMODE_HEIGHT,NULL},
        {&screenmodegads[3],303,112,32,8,
            GFLG_GADGHCOMP|GFLG_STRINGEXTEND|GFLG_TABCYCLE,GACT_RELVERIFY|GACT_TOGGLESELECT|GACT_LONGINT,
            GTYP_STRGADGET,NULL,NULL,NULL,0,(APTR)&screendepthsinfo,SCREENMODE_DEPTH,NULL},
        {&screenmodegads[4],381,81,26,11,
            GFLG_GADGIMAGE|GFLG_GADGHIMAGE,GACT_RELVERIFY|GACT_TOGGLESELECT,
            GTYP_BOOLGADGET,(APTR)&copy_checkoffimage,(APTR)&copy_checkonimage,NULL,GAD_CHECK,NULL,
            SCREENMODE_DEFWIDTH,NULL},
        {&screenmodegads[5],381,96,26,11,
            GFLG_GADGIMAGE|GFLG_GADGHIMAGE,GACT_RELVERIFY|GACT_TOGGLESELECT,
            GTYP_BOOLGADGET,(APTR)&copy_checkoffimage,(APTR)&copy_checkonimage,NULL,GAD_CHECK,NULL,
            SCREENMODE_DEFHEIGHT,NULL},
        {&screenmodegads[6],299,126,26,11,
            GFLG_GADGIMAGE|GFLG_GADGHIMAGE,GACT_RELVERIFY|GACT_TOGGLESELECT,
            GTYP_BOOLGADGET,(APTR)&copy_checkoffimage,(APTR)&copy_checkonimage,NULL,GAD_CHECK,NULL,
            SCREENMODE_HALFHEIGHT,NULL},
        {NULL,345,112,165,8,
            GFLG_GADGHNONE,GACT_RELVERIFY,
            GTYP_PROPGADGET,(APTR)&screenmodeimage,NULL,NULL,0,(APTR)&screenmodeprop,
            SCREENMODE_SLIDER,NULL}},
    formatgads[11 /* HUX: was 10 */]={
        {&formatgads[1],366,19,150,14,
            GFLG_GADGHCOMP,GACT_RELVERIFY,
            GTYP_BOOLGADGET,NULL,NULL,NULL,GAD_CYCLE,NULL,FORMAT_WINDOW,NULL},
//HUX
        {&formatgads[2],417,183,26,11,
            GFLG_GADGIMAGE|GFLG_GADGHIMAGE,GACT_RELVERIFY|GACT_TOGGLESELECT,
            GTYP_BOOLGADGET,(APTR)&copy_checkoffimage,(APTR)&copy_checkonimage,NULL,GAD_CHECK,NULL,
            FORMAT_SIZEKMG,NULL},
//HUX
        {&formatgads[3],465,123,104,12,
            GFLG_GADGHCOMP,GACT_RELVERIFY,
            GTYP_BOOLGADGET,NULL,NULL,NULL,0,NULL,FORMAT_RESET,NULL},
        {&formatgads[4],465,137,104,12,
            GFLG_GADGHCOMP,GACT_RELVERIFY,
            GTYP_BOOLGADGET,NULL,NULL,NULL,0,NULL,FORMAT_CLEAR,NULL},
        {&formatgads[5],417,167,208,14, // JRZ
            GFLG_GADGHCOMP,GACT_RELVERIFY,
            GTYP_BOOLGADGET,NULL,NULL,NULL,GAD_CYCLE,NULL,FORMAT_SEPARATE,NULL},
        {&formatgads[6],417,183,26,11,
            GFLG_GADGIMAGE|GFLG_GADGHIMAGE,GACT_RELVERIFY|GACT_TOGGLESELECT,
            GTYP_BOOLGADGET,(APTR)&copy_checkoffimage,(APTR)&copy_checkonimage,NULL,GAD_CHECK,NULL,
            FORMAT_REVERSESORT,NULL},
        {&formatgads[7],552,52,40,8,
            GFLG_GADGHCOMP|GFLG_STRINGEXTEND|GFLG_TABCYCLE,GACT_RELVERIFY|GACT_TOGGLESELECT|GACT_LONGINT,
            GTYP_STRGADGET,NULL,NULL,NULL,0,(APTR)&formatlensinfo[0],FORMAT_LENGTH+0,NULL},
        {&formatgads[8],552,78,40,8,
            GFLG_GADGHCOMP|GFLG_STRINGEXTEND|GFLG_TABCYCLE,GACT_RELVERIFY|GACT_TOGGLESELECT|GACT_LONGINT,
            GTYP_STRGADGET,NULL,NULL,NULL,0,(APTR)&formatlensinfo[1],FORMAT_LENGTH+1,NULL},
        {NULL,552,91,40,8,
            GFLG_GADGHCOMP|GFLG_STRINGEXTEND|GFLG_TABCYCLE,GACT_RELVERIFY|GACT_TOGGLESELECT|GACT_LONGINT,
            GTYP_STRGADGET,NULL,NULL,NULL,0,(APTR)&formatlensinfo[2],FORMAT_LENGTH+2,NULL},
        {&formatgads[10],552,104,40,8,
            GFLG_GADGHCOMP|GFLG_STRINGEXTEND|GFLG_TABCYCLE,GACT_RELVERIFY|GACT_TOGGLESELECT|GACT_LONGINT,
            GTYP_STRGADGET,NULL,NULL,NULL,0,(APTR)&formatlensinfo[3],FORMAT_LENGTH+3,NULL},
        {NULL,552,117,40,8,
            GFLG_GADGHCOMP|GFLG_STRINGEXTEND|GFLG_TABCYCLE,GACT_RELVERIFY|GACT_TOGGLESELECT|GACT_LONGINT,
            GTYP_STRGADGET,NULL,NULL,NULL,0,(APTR)&formatlensinfo[4],FORMAT_LENGTH+4,NULL}},
    icongads[4]={
        {&icongads[1],140,137,28,14,
            GFLG_GADGHCOMP,GACT_RELVERIFY,
            GTYP_BOOLGADGET,NULL,NULL,NULL,GAD_GLASS,NULL,ICON_ICONREQ,NULL},
        {&icongads[2],176,140,275,8,
            GFLG_GADGHCOMP|GFLG_STRINGEXTEND|GFLG_TABCYCLE,GACT_RELVERIFY|GACT_TOGGLESELECT,
            GTYP_STRGADGET,NULL,NULL,NULL,1,(APTR)&funcsinfo,ICON_ICONPATH,NULL},
        {&icongads[3],140,165,28,14,
            GFLG_GADGHCOMP,GACT_RELVERIFY,
            GTYP_BOOLGADGET,NULL,NULL,NULL,GAD_GLASS,NULL,ICON_TOOLREQ,NULL},
        {NULL,176,168,275,8,
            GFLG_GADGHCOMP|GFLG_STRINGEXTEND|GFLG_TABCYCLE,GACT_RELVERIFY|GACT_TOGGLESELECT,
            GTYP_STRGADGET,NULL,NULL,NULL,1,(APTR)&pathsinfo,ICON_TOOLPATH,NULL}},
    hotkeymmbgad={
        NULL,138,97,26,11,
        GFLG_GADGIMAGE|GFLG_GADGHIMAGE,GACT_RELVERIFY|GACT_TOGGLESELECT,
        GTYP_BOOLGADGET,(APTR)&copy_checkoffimage,(APTR)&copy_checkonimage,NULL,GAD_CHECK,NULL,
        HOTKEY_MMB,NULL},
    hotkeygad={
        &hotkeymmbgad,514,82,104,12,
        GFLG_GADGHCOMP,GACT_RELVERIFY|GACT_TOGGLESELECT,
        GTYP_BOOLGADGET,NULL,NULL,NULL,0,NULL,HOTKEY_SAMPLE,NULL},
    arrowgadgets[8]={
        {&arrowgadgets[1],237,111,15,9,
            GFLG_GADGIMAGE|GFLG_GADGHIMAGE,GACT_IMMEDIATE|GACT_TOGGLESELECT,
            GTYP_BOOLGADGET,NULL,NULL,NULL,GAD_RADIO,NULL,ARROWBASE,NULL},
        {&arrowgadgets[2],237,121,15,9,
            GFLG_GADGIMAGE|GFLG_GADGHIMAGE,GACT_IMMEDIATE|GACT_TOGGLESELECT,
            GTYP_BOOLGADGET,NULL,NULL,NULL,GAD_RADIO,NULL,ARROWBASE+1,NULL},
        {&arrowgadgets[3],237,131,15,9,
            GFLG_GADGIMAGE|GFLG_GADGHIMAGE,GACT_IMMEDIATE|GACT_TOGGLESELECT,
            GTYP_BOOLGADGET,NULL,NULL,NULL,GAD_RADIO,NULL,ARROWBASE+2,NULL},
        {&arrowgadgets[4],420,155,14,11,
            GFLG_GADGHCOMP,GACT_RELVERIFY|GACT_IMMEDIATE,
            GTYP_BOOLGADGET,NULL,NULL,NULL,0,NULL,ARROWBASE+3,NULL},
        {&arrowgadgets[5],454,155,14,11,
            GFLG_GADGHCOMP,GACT_RELVERIFY|GACT_IMMEDIATE,
            GTYP_BOOLGADGET,NULL,NULL,NULL,0,NULL,ARROWBASE+4,NULL},
        {&arrowgadgets[6],436,149,16,11,
            GFLG_GADGHCOMP,GACT_RELVERIFY|GACT_IMMEDIATE,
            GTYP_BOOLGADGET,NULL,NULL,NULL,0,NULL,ARROWBASE+5,NULL},
        {&arrowgadgets[7],436,161,16,11,
            GFLG_GADGHCOMP,GACT_RELVERIFY|GACT_IMMEDIATE,
            GTYP_BOOLGADGET,NULL,NULL,NULL,0,NULL,ARROWBASE+6,NULL},
        {NULL,247,23,248,14,
            GFLG_GADGHCOMP,GACT_RELVERIFY,
            GTYP_BOOLGADGET,NULL,NULL,NULL,GAD_CYCLE,NULL,ARROWCYCLE,NULL}},
    fontsizegadget={
        NULL,570,85,44,8,
        GFLG_GADGHCOMP|GFLG_STRINGEXTEND|GFLG_TABCYCLE,GACT_RELVERIFY|GACT_TOGGLESELECT|GACT_STRINGCENTER,
        GTYP_STRGADGET,NULL,NULL,NULL,0,(APTR)&fontsizesinfo,FONT_SIZE,NULL},
    editclassgadgets[14]={
        {&editclassgadgets[1],97,87,352,8,
            GFLG_GADGHCOMP|GFLG_STRINGEXTEND|GFLG_TABCYCLE,GACT_RELVERIFY|GACT_TOGGLESELECT,
            GTYP_STRGADGET,NULL,NULL,NULL,0,(APTR)&namesinfo,CLASS_TYPE,NULL},
        {&editclassgadgets[2],540,87,88,8,
            GFLG_GADGHCOMP|GFLG_STRINGEXTEND|GFLG_TABCYCLE,GACT_RELVERIFY|GACT_TOGGLESELECT,
            GTYP_STRGADGET,NULL,NULL,NULL,0,(APTR)&typeidsinfo,CLASS_TYPEID,NULL},
        {&editclassgadgets[3],28,169,104,12,
            GFLG_GADGHCOMP,GACT_RELVERIFY,
            GTYP_BOOLGADGET,NULL,NULL,NULL,0,NULL,CLASS_NEWENTRY,NULL},
        {&editclassgadgets[4],188,169,104,12,
            GFLG_GADGHCOMP,GACT_RELVERIFY,
            GTYP_BOOLGADGET,NULL,NULL,NULL,0,NULL,CLASS_DUPLICATE,NULL},
        {&editclassgadgets[5],348,169,104,12,
            GFLG_GADGHCOMP,GACT_RELVERIFY|GACT_TOGGLESELECT,
            GTYP_BOOLGADGET,NULL,NULL,NULL,0,NULL,CLASS_SWAP,NULL},
        {&editclassgadgets[6],508,169,104,12,
            GFLG_GADGHCOMP,GACT_RELVERIFY,
            GTYP_BOOLGADGET,NULL,NULL,NULL,0,NULL,CLASS_DELETE,NULL},
        {&editclassgadgets[7],9,151,28,14,
            GFLG_GADGHCOMP,GACT_RELVERIFY,
            GTYP_BOOLGADGET,NULL,NULL,NULL,0,NULL,CLASS_OPERATION,NULL},
        {&editclassgadgets[8],167,154,458,8,
            GFLG_GADGHCOMP|GFLG_STRINGEXTEND|GFLG_TABCYCLE,GACT_RELVERIFY|GACT_TOGGLESELECT,
            GTYP_STRGADGET,NULL,NULL,NULL,1,(APTR)&funcsinfo,CLASS_FUNC,NULL},
        {&editclassgadgets[9],106,16,28,14,
            GFLG_GADGHCOMP,GACT_RELVERIFY,
            GTYP_BOOLGADGET,NULL,NULL,NULL,GAD_GLASS,NULL,CLASS_FILEVIEWREQ,NULL},
        {&editclassgadgets[10],142,19,386,8,
            GFLG_GADGHCOMP|GFLG_STRINGEXTEND|GFLG_TABCYCLE,GACT_RELVERIFY|GACT_TOGGLESELECT,
            GTYP_STRGADGET,NULL,NULL,NULL,1,(APTR)&pathsinfo,CLASS_FILEVIEW,NULL},
        {&editclassgadgets[11],536,16,95,14,
            GFLG_GADGHCOMP,GACT_RELVERIFY,
            GTYP_BOOLGADGET,NULL,NULL,NULL,GAD_CYCLE,NULL,CLASS_HEXDEC,NULL},
        {&editclassgadgets[12],522,34,8,30,
            GFLG_GADGHNONE,GACT_IMMEDIATE|GACT_FOLLOWMOUSE|GACT_RELVERIFY,
            GTYP_PROPGADGET,(APTR)&fileviewimage,NULL,NULL,0,(APTR)&fileviewprop,CLASS_VIEWSLIDER,NULL},
        {&editclassgadgets[13],518,66,16,8,
            GFLG_GADGHCOMP,GACT_IMMEDIATE|GACT_RELVERIFY,
            GTYP_BOOLGADGET,NULL,NULL,NULL,0,NULL,CLASS_VIEWUP,NULL},
        {NULL,518,74,16,8,
            GFLG_GADGHCOMP,GACT_IMMEDIATE|GACT_RELVERIFY,
            GTYP_BOOLGADGET,NULL,NULL,NULL,0,NULL,CLASS_VIEWDOWN,NULL}},

    screen_sliders_gadgets[]={
        {&screen_sliders_gadgets[1],229,11,97,14,
            GFLG_GADGHCOMP,GACT_RELVERIFY,
            GTYP_BOOLGADGET,NULL,NULL,NULL,GAD_CYCLE,NULL,SCREEN_SLIDER_LEFTCYCLE,NULL},
        {NULL,420,11,97,14,
            GFLG_GADGHCOMP,GACT_RELVERIFY,
            GTYP_BOOLGADGET,NULL,NULL,NULL,GAD_CYCLE,NULL,SCREEN_SLIDER_RIGHTCYCLE,NULL}};

extern UBYTE glass_data[2][36];
extern UBYTE uparrow_data[];
extern UBYTE downarrow_data[];

char
    *windownames[2],
    *separatenames[3];

int gadflagvals[]={
    FF_AUTOICONIFY,FF_CDDEST,FF_CDSOURCE,FF_DOPUS2F,FF_DOALLFILES,
    FF_DOPUSSTARTUP,FF_SHELLSTARTUP,FF_NOQUOTE,FF_OUTPUTFILE,FF_OUTPUTWIN,
    FF_RECURSEDIR,FF_RELOADFILE,FF_RESCANDEST,FF_RESCANSOURCE,
    FF_RUNASYNC,FF_WB2F};

short
    editfuncgadgets_xy[15][2]={
        {254,42},
        {508,54},
        {21,68},
        {21,81},
        {21,94},
        {21,107},
        {528,130},
        {528,144},
        {528,158},
        {128,111},
        {253,111},
        {289,114},
        {584,111},
        {175,57},
        {484,19}},
    editdrivegadgets_xy[4][2]={
        {246,102},
        {486,128},
        {148,113},
        {184,116}},
    menuslidergads_xy[3][2]={
        {614,22},
        {610,118},
        {610,126}},
    palettegads_xy[6][2]={
        {298,53},
        {298,66},
        {298,79},
        {252,53},
        {252,66},
        {252,79}},
    coloursgad_xy[2]={
        252,4},
    screenmodegads_xy[7][2]={
        {301,67},
        {301,82},
        {301,97},
        {379,66},
        {379,81},
        {297,111},
        {343,97}},
    formatgads_xy[11 /* HUX: was 10 */][2]={
        {364,7},
        {415,116}, //HUX // JRZ
        {415,130}, // JRZ
        {519,130}, // JRZ
        {415,155},
        {415,171},
        {550,40},
        {550,53},
        {550,66},
        {550,79},
        {550,92}},
    icongads_xy[4][2]={
        {138,125},
        {174,128},
        {138,153},
        {174,156}},
    hotkeymmbgad_xy[2]={
        136,85},
    hotkeygad_xy[2]={
        512,70},
    arrowgadgets_xy[8][2]={
        {235,99},
        {235,109},
        {235,119},
        {418,143},
        {452,143},
        {434,137},
        {434,149},
        {245,11}},
    fontsizegadget_xy[2]={
        568,73},
    editclassgadgets_xy[14][2]={
        {93,75},
        {536,75},
        {24,157},
        {184,157},
        {344,157},
        {504,157},
        {5,139},
        {163,142},
        {102,4},
        {138,7},
        {532,4},
        {518,22},
        {514,54},
        {514,62}},
    screen_sliders_gadgets_xy[2][2]={
        {229,11},
        {420,11}};
