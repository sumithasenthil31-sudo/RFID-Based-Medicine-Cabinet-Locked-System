#ifndef UART_H
#define UART_H

#include "pins.h"

void UART0_INIT(void)
{
    PINSEL0 = (PINSEL0 & ~0x0000000F) | 0x00000005;
    U0LCR = 0x83;
    U0DLL = 97;
    U0DLM = 0;
    U0LCR = 0x03;
}

char UART0_RX(void)
{
    while (!(U0LSR & 0x01));

    return U0RBR;
}

#endif
