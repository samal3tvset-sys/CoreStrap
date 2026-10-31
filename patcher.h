#ifndef PATCHER_H
#define PATCHER_H

#include <stdint.h>

void patcher_init(void);
int patch_device_tree(uintptr_t dtb_addr);

#endif
