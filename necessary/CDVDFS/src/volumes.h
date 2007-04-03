#ifndef VOLUMES_H
#define VOLUMES_H

#include <exec/ports.h>
#include "device.h"

typedef struct lock_node {
  LOCK *lock;
  char *vol_name;
  t_path_list pathlist;
  struct lock_node *next;
} t_lock_node;

typedef struct fh_node {
  char *vol_name;
  CDROM_OBJ* obj;
  struct DeviceList* devlist;
  struct fh_node *next;
} t_fh_node;

typedef struct vol_reg_node {
  char *name;
  struct DeviceList *volume;
  struct vol_reg_node *next;
} t_vol_reg_node;


void Register_Lock (LOCK *p_lock);
void Unregister_Lock (LOCK *p_lock);
int Reinstall_Locks (void);
void Register_File_Handle(CDROM_OBJ *p_obj);
void Unregister_File_Handle(CDROM_OBJ *p_obj);
struct DeviceList *Find_Dev_List (CDROM_OBJ *p_obj);
int Reinstall_File_Handles (void);
void Register_Volume_Node(struct DeviceList *p_volume);
void Unregister_Volume_Node(struct DeviceList *p_volume);
struct DeviceList *Find_Volume_Node(char *p_name);

#endif /* VOLUMES_H */

