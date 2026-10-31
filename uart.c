#include "corestrap.h"

#define UART_BASE 0x13800000 
#define UART_UFCON  (*(volatile uint32_t *)(UART_BASE + 0x08))
#define UART_UTXH   (*(volatile uint32_t *)(UART_BASE + 0x20))
#define UART_UTRSTAT (*(volatile uint32_t *)(UART_BASE + 0x10))

void uart_init(void) {
    UART_UFCON = 0x1;
}

void uart_send_char(char c) {
    while (!(UART_UTRSTAT & 0x2));
    UART_UTXH = c;
}

void uart_print(const char *str) {
    while (*str) {
        if (*str == '\n') {
            uart_send_char('\r');
        }
        uart_send_char(*str++);
    }
}
