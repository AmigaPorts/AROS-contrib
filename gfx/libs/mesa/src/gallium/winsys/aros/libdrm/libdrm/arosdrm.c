#include "arosdrm.h"
#include "drmP.h"
#include "nouveau_drm.h"
#include "nouveau_drv.h"

#define DEBUG 1
#include <aros/debug.h>

/* FIXME: This should implement generic approach - not card specific */

int drm_debug_flag = 0;

struct drm_device global_drm_device;

int 
drmCommandNone(int fd, unsigned long drmCommandIndex)
{
    switch(drmCommandIndex)
    {
        case(DRM_NOUVEAU_CARD_INIT):
            return nouveau_ioctl_card_init(&global_drm_device, NULL, NULL);
        default:
            D(bug("drmCommandNone - UNHANDLED %d\n", drmCommandIndex));
    }
    
    return 0;
}

int
drmCommandRead(int fd, unsigned long drmCommandIndex, void *data, unsigned long size)
{
    D(bug("drmCommandRead - %d\n", drmCommandIndex));
    return 0;
}

int
drmCommandWrite(int fd, unsigned long drmCommandIndex, void *data, unsigned long size)
{
    D(bug("drmCommandWrite - %d\n", drmCommandIndex));
    return 0;
}

int
drmCommandWriteRead(int fd, unsigned long drmCommandIndex, void *data, unsigned long size)
{
    D(bug("drmCommandWriteRead - %d\n", drmCommandIndex));
    return 0;
}
 
int           
drmMap(int fd, drm_handle_t handle, drmSize size, drmAddressPtr address)
{
    D(bug("drmMap\n"));
    return 0;
}

int
drmUnmap(drmAddress address, drmSize size)
{
    D(bug("drmUnmap\n"));
    return 0;
}

int
drmOpen(const char *name, const char *busid)
{
    D(bug("drmOpen %s, %s\n", name, busid));
    return 4242; /*FIXME: some id just for now */
}

int
drmClose(int fd)
{
    D(bug("drmClose\n"));
    return 0;
}

drmVersionPtr
drmGetVersion(int fd)
{
    static drmVersion ver;
    D(bug("drmGetVersion\n"));
    ver.version_patchlevel = NOUVEAU_DRM_HEADER_PATCHLEVEL;
    return &ver;
}

void
drmFreeVersion(drmVersionPtr ptr)
{
    D(bug("drmFreeVersion\n"));
}

int
drmCreateContext(int fd, drm_context_t * handle)
{
    D(bug("drmCreateContext\n"));
    return 0;
}

int
drmDestroyContext(int fd, drm_context_t handle)
{
    D(bug("drmDestroyContext\n"));
    return 0;
}

