#ifndef HIDD_GALLIUM_H
#define HIDD_GALLIUM_H

/*
    Copyright 2010, The AROS Development Team. All rights reserved.
    $Id$
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef HIDD_HIDD_H
#include <hidd/hidd.h>
#endif

#ifndef OOP_OOP_H
#include <oop/oop.h>
#endif

/* Gallium BaseDriver class */

#define CLID_Hidd_GalliumBaseDriver   "hidd.gallium.basedriver"
#define IID_Hidd_GalliumBaseDriver    "hidd.gallium.basedriver"

#define HiddGalliumBaseDriverAttrBase	__IHidd_GalliumBaseDriver

#ifndef __OOP_NOATTRBASES__
extern OOP_AttrBase HiddGalliumBaseDriverAttrBase;
#endif

/* Gallium BaseDriver Class methods */

enum
{
    moHidd_GalliumBaseDriver_CreatePipeScreen = 0,
    moHidd_GalliumBaseDriver_QueryDepthStencil,
    moHidd_GalliumBaseDriver_DisplaySurface,

    NUM_GALLIUMBASEDRIVER_METHODS
};

enum
{
    aoHidd_GalliumBaseDriver_GalliumInterfaceVersion = 0,
    
    num_Hidd_GalliumBaseDriver_Attrs
};

#define aHidd_GalliumBaseDriver_GalliumInterfaceVersion  (HiddGalliumBaseDriverAttrBase + aoHidd_GalliumBaseDriver_GalliumInterfaceVersion)

#define IS_GALLIUMBASEDRIVER_ATTR(attr, idx) \
    (((idx) = (attr) - HiddGalliumBaseDriverAttrBase) < num_Hidd_GalliumBaseDriver_Attrs)

struct pHidd_GalliumBaseDriver_CreatePipeScreen
{
    OOP_MethodID    mID;
};

struct pHidd_GalliumBaseDriver_QueryDepthStencil
{
    OOP_MethodID    mID;
    UBYTE           *depthbits;
    UBYTE           *stencilbits;
};

struct pHidd_GalliumBaseDriver_DisplaySurface
{
    OOP_MethodID    mID;
    APTR            rastport;
    ULONG           left;
    ULONG           top;
    ULONG           width;
    ULONG           height;
    APTR            surface;
};

/* Gallium DriverFactory class */

#define CLID_Hidd_GalliumDriverFactory    "hidd.gallium.driverfactory"
#define IID_Hidd_GalliumDriverFactory     "hidd.gallium.driverfactory"

#define HiddGalliumDriverFactoryAttrBase  __IHidd_GalliumDriverFactory

#ifndef __OOP_NOATTRBASES__
extern OOP_AttrBase HiddGalliumDriverFactoryAttrBase;
#endif

/* Gallium DriverFactory Class methods */
enum
{
    moHidd_GalliumDriverFactory_GetDriver = 0,

    NUM_GALLIUMDRIVERFACTORY_METHODS
};

struct pHidd_GalliumDriverFactory_GetDriver
{
    OOP_MethodID    mID;
    ULONG           galliuminterfaceversion;
};

#endif
