#ifndef _LS2K1000_H__
#define _LS2K1000_H__

#include <mips.h>

#define UART0_BASE_ADDR 0xbfe00000
#define UART0_OFF   0x0
#define UART4_OFF   0x400
#define UART0_BASE CKSEG1ADDR(UART0_BASE_ADDR + UART0_OFF)
//#define UART1_BASE 0xFFFFFFFFBFE00400

//#define UART0_BASE 0xFFFFFFFFBFE00000

//#define UART1_BASE 0xFFFFFFFFBFE00100

#define UART4_BASE CKSEG1ADDR(UART0_BASE_ADDR + UART4_OFF)

#define GPIO_BASE 0xFFFFFFFFBFE10500

void rt_hw_timer_handler(void);
void rt_hw_uart_init(void);

#endif

