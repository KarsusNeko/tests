#ifndef __DRIVERS_H
#define __DRIVERS_H

#include "dev_list.h"

extern dev_list __dev_lst;

void dev_init();
void dev_register(dev_node* dev_node);
int dev_unregister(char* name);

int dev_open(char* name);
int dev_close(char* name);
int dev_read(char* name, void* buf, int size);
int dev_write(char* name, void* buf, int size);
int dev_ctrl(char* name, int cmd, void* arg);

#endif // __DRIVERS_H
