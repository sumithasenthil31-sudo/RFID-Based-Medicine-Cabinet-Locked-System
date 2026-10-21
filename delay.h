#ifndef DELAY_H
#define DELAY_H

#include "pins.h"

void delay_milliseconds(unsigned int ms)
{
    T0TCR = 0x02;
    T0PR  = 15000 - 1;
    T0TC  = 0;
    T0TCR = 0x01;

    while (T0TC < ms);

    T0TCR = 0x00;
}

#endif
