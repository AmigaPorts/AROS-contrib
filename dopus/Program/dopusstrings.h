/****************************************************************

   This file was created automatically by `FlexCat 2.5'
   from "../catalogs/DOpus4.cd".

   Do NOT edit by hand!

****************************************************************/

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

/* List of internal strings */

#ifndef DOPUS_STRINGS
#define DOPUS_STRINGS

enum {
	STR_DIRS_FILES_BYTES_COUNT=0,
	STR_DOPUS_ALREADY_RUNNING=1,
	STR_UNABLE_TO_OPEN_WINDOW=2,
	STR_WELCOME_TO_DOPUS=3,
	STR_WELCOME_BACK_TO_DOPUS=4,
	STR_INTERROGATING_FILE=5,
	STR_READING_DIRECTORY=6,
	STR_ENTER_ARGUMENTS_FOR=7,
	STR_ENTER_DIRECTORY_NAME=8,
	STR_FILE_ALREADY_EXISTS=9,
	STR_DIRECTORY_CREATED=10,
	STR_PRINTING_DIRECTORY=11,
	STR_DIRECTORY=12,
	STR_DEVICE_LIST=13,
	STR_NO_CHIP_FOR_ICON=14,
	STR_FILE_NOT_ILBM=15,
	STR_ERROR_IN_IFF=16,
	STR_NO_CHIP_FOR_PICTURE=17,
	STR_CANT_ALLOCATE_AUDIO=18,
	STR_NOT_ST_MOD=19,
	STR_FILE_EXISTS_REPLACE=20,
	STR_SELECT_UNPROTECT=21,
	STR_ENTER_TIME=22,
	STR_AREXX_NOT_RUNNING=23,
	STR_ENTER_AREXX_COMMAND=24,
	STR_ENTER_NEW_CD=25,
	STR_SCANNING_DEVICE_LIST=26,
	STR_FOUND_A_MATCH=27,
	STR_BUFFERS_CLEARED=28,
	STR_UNREADABLE_DISK=29,
	STR_NOT_A_DOS_DISK=30,
	STR_KICKSTART_DISK=31,
	STR_VALIDATING=32,
	STR_WRITE_PROTECTED=33,
	STR_READ_WRITE=34,
	STR_DEVICE_NOT_MOUNTED=35,
	STR_NO_DISK_IN_DRIVE=36,
	STR_DOS_ERROR_CODE=37,
	STR_ENTER_NEW_DISK_NAME=38,
	STR_ENTER_ASSIGN_NAME=39,
	STR_CANT_CANCEL_ASSIGN=40,
	STR_ENTER_DEVICE_NAME=41,
	STR_ASSIGN_FAILED=42,
	STR_NO_DESTINATION_SELECTED=43,
	STR_CANT_COPY_DIR_TO_ITSELF=44,
	STR_SHOWING_FONT=45,
	STR_RUNNING_FILE=46,
	STR_PLAYING_FILE=47,
	STR_SHOWING_FILE=48,
	STR_PLAYING_ST_MOD=49,
	STR_READING_SELECTED_FILE=50,
	STR_FOUND_A_MATCH_READ=51,
	STR_CONFIG_CHANGED_QUIT=52,
	STR_SAVING_CONFIG=53,
	STR_READING_CONFIG=54,
	STR_CONFIG_CHANGED_LASTSAVED=55,
	STR_CONFIG_CHANGED_DEFAULTS=56,
	STR_HELP_NOT_AVAILABLE=57,
	STR_SCANNING_TREE=58,
	STR_ENTER_A_STRING=59,
	STR_PLEASE_CHOOSE=60,
	STR_COMMENTING=61,
	STR_PROTECTING=62,
	STR_DATESTAMPING=63,
	STR_DELETING=64,
	STR_COPYING=65,
	STR_CREATING=66,
	STR_CANT_OVERCOPY_FILES=67,
	STR_INTERROGATING_FILES=68,
	STR_NOT_IDENTIFIED=69,
	STR_LOADING_CONFIG=70,
	STR_WAITING_FOR_PORT=71,
	STR_CONFIG_NOT_FOUND=72,
	STR_ALIEN_WINDOWS=73,
	STR_REALLY_DELETE=74,
	STR_WISH_TO_DELETE=75,
	STR_NOT_EMPTY=76,
	STR_ENTER_NEW_NAME=77,
	STR_RENAMING=78,
	STR_ENTER_NEW_NAME_MOVE=79,
	STR_MOVING=80,
	STR_ENTER_NEW_NAME_CLONE=81,
	STR_CLONING=82,
	STR_SIZE_IS_NOT_KNOWN=83,
	STR_FILE_MAY_NOT_FIT=84,
	STR_SIZES_NOT_KNOWN=85,
	STR_ENTRIES_MAY_NOT_FIT=86,
	STR_ENTER_NEW_NAME_COPY=87,
	STR_ENTER_HUNT_PATTERN=88,
	STR_COULD_NOT_FIND_FILE=89,
	STR_FOUND_MATCHING_FILES=90,
	STR_ADDING_ICON=91,
	STR_SELECT_COMMENT=92,
	STR_ENTER_COMMENT=93,
	STR_CANNOT_CLOSE_SCREEN=94,
	STR_ENTER_PASSWORD=95,
	STR_ENTER_DATE_AND_TIME=97,
	STR_ENTER_SEARCH_STRING=98,
	STR_RENAME_REQ=99,
	STR_STRING_NOT_FOUND=100,
	STR_MATCHED_FILES=101,
	STR_NO_SOURCE_SELECTED=102,
	STR_TEMPORARY_OUTPUT_FILE=103,
	STR_ENTER_ARGUMENTS=104,
	STR_SELECT_FUNCTION=105,
	STR_CONFIG_CHANGED_LOAD=140,
	STR_ABORTED=141,
	STR_ENTER_DOS_ERROR_CODE=142,
	STR_NO_HELP_FOR_ERROR=143,
	STR_ERROR_OCCURED=144,
	STR_RENAME=145,
	STR_AS=146,
	STR_ENTER_SELECT_PATTERN=147,
	STR_FILE_ENCRYPTED=148,
	STR_READING_FILE=149,
	STR_NO_MEMORY_TO_DECRUNCH=150,
	STR_BAD_PASSWORD=151,
	STR_COUNTING_LINES=152,
	STR_JUMP_TO_LINE=153,
	STR_JUMP_TO_PERCENTAGE=154,
	STR_CANT_OPEN_PRINTER=155,
	STR_ERROR_PRINTING_FILE=156,
	STR_READY_PRINTER=157,
	STR_CANT_FIND_ICON=158,
	STR_ENCRYPTING=159,
	STR_NEW_DISK_INSERTED=160,
	STR_REPLACE_ALL=161,
	STR_ENTER_DATE_1=162,
	STR_ENTER_DATE_2=163,
	STR_ENTER_DATE_3=164,
	STR_ENTER_DATE_4=165,
	STR_CONTINUE_WITH_SEARCH=166,
	STR_REALLY_QUIT=167,
	STR_REALLY_PROCEED=168,
	STR_SCREEN_MODE_UNAVAILABLE=169,
	STR_ERROR_INITIALISING_PRINTER=170,
	STR_REALLY_ABORT_PRINT=171,
	STR_SELECT_SOURCE_DIR=172,
	STR_SELECT_DESTINATION_DIR=173,
	STR_SELECT_A_FILE=174,
	STR_SELECT_A_DIRECTORY=175,
	STR_LEFT_WINDOW=176,
	STR_RIGHT_WINDOW=177,
	STR_DEVICE_LIST_TITLE=178,
	STR_DIR_NOT_AVAILABLE_TITLE=179,
	STR_BUFFER_LIST_TITLE=180,
	STR_UNPROTECT=181,
	STR_RUN=182,
	STR_TRY_AGAIN=183,
	STR_RETRY=184,
	STR_ABORT=185,
	STR_REPLACE=186,
	STR_SKIP=187,
	STR_ALL=188,
	STR_REMOVE=189,
	STR_QUIT=190,
	STR_SAVE_QUIT=191,
	STR_LOAD=192,
	STR_SAVE=193,
	STR_DEFAULTS=194,
	STR_CLOSE=195,
	STR_DELETE=196,
	STR_LEAVE=197,
	STR_YES=198,
	STR_NO=199,
	STR_ICONIFY=200,
	STR_CONTINUE=201,
	STR_OKAY=202,
	STR_CANCEL=203,
	STR_OKAY_TITLE=204,
	STR_DESCRIPTION=205,
	STR_PRINT_CONTROL=206,
	STR_FILE=207,
	STR_IMAGE_SIZE=208,
	STR_PAGE_SIZE=209,
	STR_SCREEN_SIZE=210,
	STR_DEPTH=211,
	STR_COLOURS=212,
	STR_SCREEN_MODES=213,
	STR_ASPECT=214,
	STR_IMAGE=215,
	STR_SHADE=216,
	STR_PLACEMENT=217,
	STR_FORMFEED=218,
	STR_PRINT=219,
	STR_ABORT_PRINT=220,
	STR_PORTRAIT=221,
	STR_LANDSCAPE=222,
	STR_POSITIVE=223,
	STR_NEGATIVE=224,
	STR_BLACK_WHITE=225,
	STR_GRAY_SCALE=226,
	STR_COLOUR=227,
	STR_CENTER=228,
	STR_FULL_LEFT=229,
	STR_FONT=230,
	STR_FONT_SIZE=231,
	STR_NUM_CHARS=232,
	STR_FONT_STYLE=233,
	STR_FONT_FLAGS=234,
	STR_ICON=235,
	STR_ICON_TYPE=236,
	STR_ICON_ALTERNATE=237,
	STR_ICON_DEFAULTTOOL=238,
	STR_NUM_FRAMES=239,
	STR_PLAYING_ANIM=240,
	STR_OLD_NEW_FILE_REPLACE=241,
	STR_REMAINING=242,
	STR_CUSTOM_LIST=243,
	STR_ENTRIES_IN_TREE=244,
	STR_DIRS_IN_BUFFERS=245,
	STR_USER_ENTRIES=246,
	STR_COMPLETED=247,
	STR_UNICONIFY=248,
	STR_CUSTPORT_NOT_FOUND=249,
	STR_CHECKFIT_STRING=250,
	STR_DIR_TREE=251,
	STR_BUILDING_TREE=252,
	STR_UNPROTECT_ALL=253,
	STR_READING_CHANGED_DIRECTORY=254,
	STR_CREATING_DIRECTORY=255,
	STR_STARTING_DISK_MODULE=256,
	STR_UNABLE_TO_LOAD_MODULE=257,
	STR_SELECT_ALL_ENTRIES=258,
	STR_SELECT_ONLY_FILES=259,
	STR_SELECT_ONLY_DIRS=260,
	STR_SELECT_NAME=261,
	STR_SELECT_DATE=262,
	STR_SELECT_BITS=263,
	STR_STARTING_PRINT_MODULE=264,
	STR_ABOUT=265,
	STR_PRINTTITLE=266,
	STR_SEARCH_NO_CASE=267,
	STR_SEARCH_WILD=268,
	STR_SEARCH_ONLYWORD=269,
	STR_ENTER_FILTER=270,
	STR_SELECT_PROTECTION_BITS=271,
	STR_DIRECTORY_OPUS_REQUEST=272,
	STR_CLOCK_CHIP=273,
	STR_CLOCK_FAST=274,
	STR_CLOCK_TOTAL=275,
	STR_CLOCK_MEM=276,
	STR_KEY=320,
	STR_TINY_BUTTONS=321,
	STR_VIEW_BUTTONS=322,
	STR_DISKINFO_DEVICE=323,
	STR_DISKINFO_NAME=324,
	STR_DISKINFO_SIZE=325,
	STR_DISKINFO_USED=326,
	STR_DISKINFO_FREE=327,
	STR_DISKINFO_PERCENT=328,
	STR_DISKINFO_DENSITY=329,
	STR_DISKINFO_ERRORS=330,
	STR_DISKINFO_STATUS=331,
	STR_DISKINFO_DATE=332,
	STR_DISKINFO_BYTES=333,
	STR_DISKINFO_BLOCKS=334,
	STR_DISKINFO_FULL=335,
	STR_DISKINFO_SFREE=336,
	STR_DISKINFO_BYTESPERBLOCK=337,
	STR_TEXT_VIEWER_TITLE=338,
	STR_PROTECT_ALL_BITS=339,
	STR_PROTECT_NONE=340,
	STR_PROTECT_TOGGLE=341,
	STR_PROTECT_REVERT=342,
	STR_PROTECT_OLD=343,
	STR_PROTECT_NEW=344,
	STR_PROTECT_MASK=345,
	STR_PROTECT_HIDDEN=346,
	STR_PROTECT_SCRIPT=347,
	STR_PROTECT_PURE=348,
	STR_PROTECT_ARCHIVE=349,
	STR_PROTECT_READ=350,
	STR_PROTECT_WRITE=351,
	STR_PROTECT_EXECUTED=352,
	STR_PROTECT_DELETED=353,
	STR_FILE_REQUEST=354,
	STR_OF=355,
	STR_FRAME=356,
	STR_DISK_OP_TITLE=357,
	STR_BUTTON_STRIP=358,
	STR_NO_FIT=359,
	STR_YES_FIT=360,
	STR_FTYPE_DEFAULT=361,
	STR_FTYPE_UNKNOWN=362,
	STR_MULTI_DRAG=366,
	STR_PRESS_MOUSE_BUTTON=367,
	STR_NETWORK_NO_OWNER=368,
	STR_NETWORK_NO_GROUP=369,
	STR_ERROR_ERROR_HELP=370,
	STR_SKIP_ALL=371,
	STR_PARENT_MULTI=372,
	STR_DISKINFO_FILESYSTEM=373,
	STR_ANIM_TYPE=374,
	STR_GFX_NATIVE=375,
	STR_OPENING_ARCHIVE=376,
	STR_LISTER_MENU=377,
	STR_FILE_NAME=378,
	STR_FILE_SIZE=379,
	STR_PROTECTION_BITS=380,
	STR_CREATION_DATE=381,
	STR_FILE_COMMENT=382,
	STR_FILE_TYPE=383,
	STR_OWNER=384,
	STR_GROUP=385,
	STR_NET_PROTECTION_BITS=386,
	STR_REVERSE_ORDER=387,
	STR_SIZE_AS_KMG=388,
	STR_BRING_TO_FRONT=389,
	STR_REPLACE_DIR_WITH_FILE=390,
	STR_REPLACE_FILE_WITH_DIR=391,
	STR_OPERATION_NOT_SUPPORTED=392,
	STR_QUERY_REMOVE_ASSIGN=393,
	STR_VERSION_CONTENTS=394,
	STR_VERSION_HEADER=395,
	STR_DIRSFIRST=396,
	STR_FILESFIRST=397,
	STR_MIXDIRSFILES=398,
	STR_SORTALPHA=399,
	STR_SORTDEC=400,
	STR_SORTHEX=401,
	STR_SORTBY=402,
	STR_NAMESORT_MENU=403,
	STR_FILE_EXTENSION=404,
	STR_PROTECT_OKAY=405,
	STR_PROTECT_ALL=406,
	STR_ENTER_MAKELINK_PARAMS=407,
	STR_MAKELINK_TYPE_SOFT=408,
	STR_MAKELINK_TYPE_HARD=409,
	STR_MAKELINK_TYPE=410,
	STR_MAKELINK_NAME=411,
	STR_MAKELINK_DESTINATION=412,
	STR_PROTECT_CANCEL=413,
    STR_STRING_COUNT};

extern const char **globstring;
extern char str_okaystring[30];
extern char str_cancelstring[30];

#endif
