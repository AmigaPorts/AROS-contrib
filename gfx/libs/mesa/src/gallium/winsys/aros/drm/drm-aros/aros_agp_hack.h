#include <exec/types.h>
#include <oop/oop.h>

/* pci.hidd (?)*/
BOOL aros_agp_hack_device_is_agp(OOP_Object * pciDevice);
BOOL aros_agp_hack_device_is_pcie(OOP_Object * pciDevice);

/* agp.hidd */
#define AGP_MEMORY_TYPE_NORMAL  1
#define AGP_MEMORY_TYPE_CACHED  2
OOP_Object * aros_agp_hack_get_agp_bridge();
BOOL aros_agp_hack_is_agp_bridge_present();
ULONG aros_agp_hack_get_bridge_mode();
IPTR aros_agp_hack_get_bridge_aperture_base();
ULONG aros_agp_hack_get_bridge_aperture_size();
VOID aros_agp_hack_bind_memory(IPTR address, ULONG size, ULONG offset, UBYTE type);
VOID aros_agp_hack_unbind_memory(ULONG offset, ULONG size);
VOID aros_agp_hack_enable_agp(ULONG mode);
VOID aros_agp_hack_flush_chipset();
