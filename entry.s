.section .text.boot
.global _start

_start:
    // Выставляем стек в конец SRAM (64К)
    ldr x0, =0x00010000
    mov sp, x0

    // Очищаем BSS секцию
    ldr x1, =__bss_start
    ldr x2, =__bss_end
1:
    cmp x1, x2
    b.hs 2f
    str wzr, [x1], #4
    b 1b

2:
    // Прыжок в Си-код CoreStrap
    bl corestrap_main

    // Если вылетели — вешаем проц в цикле
3:
    wfe
    b 3b
