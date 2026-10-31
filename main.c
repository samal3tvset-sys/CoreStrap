
#include "corestrap.h"
#include "patcher.h"
#include "config.h"

void corestrap_main(void) {
    uart_init();
    
    uart_print("\n[+] CoreStrap v0.1 booting...\n");
    uart_print("[+] Target: Samsung Galaxy A10 (Exynos 7884)\n");

    patcher_init();
    
    if (patch_device_tree(EXYNOS_DTB_BASE_ADDR) == 0) {
        uart_print("[OK] Environment ready. Ready to boot kernel.\n");
    } else {
        uart_print("[ERR] Boot sequence halted.\n");
    }

    while (1) {
        // Ожидание
    }
}
