#ifndef CONFIG_H
#define CONFIG_H

// Флаги конфигурации CoreStrap
#define CONFIG_ENABLE_UART_DEBUG    1
#define CONFIG_PATCH_DEVICE_TREE    1
#define CONFIG_EMULATE_IBOOT_NVRAM  1

// Адреса в памяти под Exynos 7884
#define EXYNOS_DTB_BASE_ADDR        0x40000000
#define EXYNOS_XNU_KERNEL_ADDR      0x45000000

#endif
