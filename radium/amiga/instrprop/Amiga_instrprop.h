/*
 *  Source machine generated by GadToolsBox V2.0b
 *  which is (c) Copyright 1991-1993 Jaba Development
 *
 *  GUI Designed by : -- Unnamed --
 */

#ifndef LIBRARIES_GADTOOLS_H
#include <libraries/gadtools.h>
#endif

#define GetString( g )      ((( struct StringInfo * )g->SpecialInfo )->Buffer  )
#define GetNumber( g )      ((( struct StringInfo * )g->SpecialInfo )->LongInt )

#define GD_name                                0
#define GD_New                                 1
#define GD_Cluster                             2
#define GD_MSB                                 3
#define GD_Preset                              4
#define GD_LSB                                 5
#define GD_Volume                              6
#define GD_Pan                                 7
#define GD_Velocity                            8
#define GD_Cr                                  9
#define GD_Re                                  10
#define GD_At                                  11
#define GD_Rl                                  12
#define GD_Cu                                  13
#define GD_Rs                                  14
#define GD_Va                                  15
#define GD_Mo                                  16
#define GD_Number                              17
#define GD_B1                                  18
#define GD_B5                                  19
#define GD_B2                                  20
#define GD_B6                                  21
#define GD_B3                                  22
#define GD_B7                                  23
#define GD_B4                                  24
#define GD_B8                                  25
#define GD_Panonoff                            26
#define GD_Volumeonoff                         27
#define GD_Channel                             28

#define GDX_name                               0
#define GDX_New                                1
#define GDX_Cluster                            2
#define GDX_MSB                                3
#define GDX_Preset                             4
#define GDX_LSB                                5
#define GDX_Volume                             6
#define GDX_Pan                                7
#define GDX_Velocity                           8
#define GDX_Cr                                 9
#define GDX_Re                                 10
#define GDX_At                                 11
#define GDX_Rl                                 12
#define GDX_Cu                                 13
#define GDX_Rs                                 14
#define GDX_Va                                 15
#define GDX_Mo                                 16
#define GDX_Number                             17
#define GDX_B1                                 18
#define GDX_B5                                 19
#define GDX_B2                                 20
#define GDX_B6                                 21
#define GDX_B3                                 22
#define GDX_B7                                 23
#define GDX_B4                                 24
#define GDX_B8                                 25
#define GDX_Panonoff                           26
#define GDX_Volumeonoff                        27
#define GDX_Channel                            28

#define CPPWindow_CNT 29

extern struct IntuitionBase *IntuitionBase;
extern struct Library       *GadToolsBase;

extern struct Screen        *Scr;
extern UBYTE                 *PubScreenName;
extern APTR                  VisualInfo;
extern struct Window        *CPPWindowWnd;
extern struct Window        *HelpWnd;
extern struct Gadget        *CPPWindowGList;
extern struct Menu          *CPPWindowMenus;
extern struct Menu          *HelpMenus;
extern struct IntuiMessage   CPPWindowMsg;
extern struct IntuiMessage   HelpMsg;
extern struct Gadget        *CPPWindowGadgets[29];
extern UWORD                 CPPWindowLeft;
extern UWORD                 CPPWindowTop;
extern UWORD                 CPPWindowWidth;
extern UWORD                 CPPWindowHeight;
extern UWORD                 HelpLeft;
extern UWORD                 HelpTop;
extern UWORD                 HelpWidth;
extern UWORD                 HelpHeight;
extern UBYTE                *CPPWindowWdt;
extern UBYTE                *HelpWdt;
extern struct TextAttr       topaz8;
extern struct NewMenu        CPPWindowNewMenu[];
extern struct NewMenu        HelpNewMenu[];
extern UWORD                 CPPWindowGTypes[];
extern struct NewGadget      CPPWindowNGad[];
extern ULONG                 CPPWindowGTags[];

extern int nameClicked( void );
extern int NewClicked( void );
extern int ClusterClicked( void );
extern int MSBClicked( void );
extern int PresetClicked( void );
extern int LSBClicked( void );
extern int VolumeClicked( void );
extern int PanClicked( void );
extern int VelocityClicked( void );
extern int CrClicked( void );
extern int ReClicked( void );
extern int AtClicked( void );
extern int RlClicked( void );
extern int CuClicked( void );
extern int RsClicked( void );
extern int VaClicked( void );
extern int MoClicked( void );
extern int NumberClicked( void );
extern int B1Clicked( void );
extern int B5Clicked( void );
extern int B2Clicked( void );
extern int B6Clicked( void );
extern int B3Clicked( void );
extern int B7Clicked( void );
extern int B4Clicked( void );
extern int B8Clicked( void );
extern int PanonoffClicked( void );
extern int VolumeonoffClicked( void );
extern int ChannelClicked( void );
extern int CPPWindowResetAllControllers( void );
extern int CPPWindowLocalKeyboardOn( void );
extern int CPPWindowLocalKeyboardOff( void );
extern int CPPWindowAllNotesOff( void );
extern int CPPWindowAllSoundsOff( void );
extern int CPPWindowSetInputLink( void );
extern int CPPWindowOx90ForNoteOff( void );
extern int HelpItem0( void );
extern int HelpItem1( void );
extern int HelpItem2( void );
extern int HelpItem3( void );
extern int HelpItem4( void );
extern int HelpItem5( void );
extern int HelpItem6( void );
extern int HelpItem7( void );
extern int HelpItem8( void );
extern int HelpItem9( void );
extern int HelpItem10( void );
extern int HelpItem11( void );
extern int HelpItem12( void );
extern int HelpItem13( void );
extern int HelpItem14( void );
extern int HelpItem15( void );
extern int HelpItem16( void );
extern int HelpItem17( void );
extern int HelpItem18( void );
extern int HelpItem19( void );
extern int HelpItem20( void );
extern int HelpItem21( void );
extern int HelpItem22( void );
extern int HelpItem23( void );
extern int HelpItem24( void );
extern int HelpItem25( void );
extern int HelpItem26( void );
extern int HelpItem27( void );
extern int HelpItem28( void );
extern int HelpItem29( void );
extern int HelpItem30( void );
extern int HelpItem31( void );
extern int HelpItem32( void );
extern int HelpItem33( void );
extern int HelpItem34( void );
extern int HelpItem35( void );
extern int HelpItem36( void );
extern int HelpItem37( void );
extern int HelpItem38( void );
extern int HelpItem39( void );
extern int HelpItem40( void );
extern int HelpItem41( void );
extern int HelpItem42( void );
extern int HelpItem43( void );
extern int HelpItem44( void );
extern int HelpItem45( void );
extern int HelpItem46( void );
extern int HelpItem47( void );
extern int HelpItem48( void );
extern int HelpItem49( void );
extern int HelpItem50( void );
extern int HelpItem51( void );
extern int HelpItem52( void );
extern int HelpItem53( void );
extern int HelpItem54( void );
extern int HelpItem55( void );
extern int HelpItem56( void );
extern int HelpItem57( void );
extern int HelpItem58( void );
extern int HelpItem59( void );
extern int HelpItem60( void );
extern int HelpItem61( void );
extern int HelpItem62( void );
extern int HelpItem63( void );
extern int HelpItem64( void );
extern int HelpItem65( void );
extern int HelpItem66( void );
extern int HelpItem67( void );
extern int HelpItem68( void );
extern int HelpItem69( void );
extern int HelpItem70( void );
extern int HelpItem71( void );
extern int HelpItem72( void );
extern int HelpItem73( void );
extern int HelpItem74( void );
extern int HelpItem75( void );
extern int HelpItem76( void );
extern int HelpItem77( void );
extern int HelpItem78( void );
extern int HelpItem79( void );
extern int HelpItem80( void );
extern int HelpItem81( void );
extern int HelpItem82( void );
extern int HelpItem83( void );
extern int HelpItem84( void );
extern int HelpItem85( void );
extern int HelpItem86( void );
extern int HelpItem87( void );
extern int HelpItem88( void );
extern int HelpItem89( void );
extern int HelpItem90( void );
extern int HelpItem91( void );
extern int HelpItem92( void );
extern int HelpItem93( void );
extern int HelpItem94( void );
extern int HelpItem95( void );
extern int HelpItem96( void );
extern int HelpItem97( void );
extern int HelpItem98( void );
extern int HelpItem99( void );
extern int HelpItem100( void );
extern int HelpItem101( void );
extern int HelpItem102( void );
extern int HelpItem103( void );
extern int HelpItem104( void );
extern int HelpItem105( void );
extern int HelpItem106( void );
extern int HelpItem107( void );
extern int HelpItem108( void );
extern int HelpItem109( void );
extern int HelpItem110( void );
extern int HelpItem111( void );
extern int HelpItem112( void );
extern int HelpItem113( void );
extern int HelpItem114( void );
extern int HelpItem115( void );
extern int HelpItem116( void );
extern int HelpItem117( void );
extern int HelpItem118( void );
extern int HelpItem119( void );
extern int HelpItem120( void );
extern int HelpItem121( void );
extern int HelpItem122( void );
extern int HelpItem123( void );
extern int HelpItem124( void );
extern int HelpItem125( void );
extern int HelpItem126( void );
extern int HelpItem127( void );
extern int HelpItem128( void );
extern int HelpItem129( void );
extern int HelpItem130( void );
extern int HelpItem131( void );
extern int HelpItem132( void );
extern int HelpItem133( void );
extern int HelpItem134( void );
extern int HelpItem135( void );
extern int HelpItem136( void );
extern int HelpItem137( void );
extern int HelpItem138( void );
extern int HelpItem139( void );
extern int HelpItem140( void );
extern int HelpItem141( void );
extern int HelpItem142( void );
extern int HelpItem143( void );
extern int HelpItem144( void );
extern int HelpItem145( void );
extern int HelpItem146( void );
extern int HelpItem147( void );
extern int HelpItem148( void );

extern int SetupScreen( void );
extern void CloseDownScreen( void );
extern int HandleCPPWindowIDCMP( void );
extern int OpenCPPWindowWindow( void );
extern void CloseCPPWindowWindow( void );
extern int HandleHelpIDCMP( void );
extern int OpenHelpWindow( void );
extern void CloseHelpWindow( void );
