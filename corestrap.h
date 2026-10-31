#ifndef CORESTRAP_H
#define CORESTRAP_H

#include <stdint.h>

// Базовые макросы и прототипы
void uart_init(void);
void uart_send_char(char c);
void uart_print(const char *str);
void corestrap_main(void);

#endif
