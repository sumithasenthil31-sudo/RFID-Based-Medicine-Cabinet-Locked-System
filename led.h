#ifndef LED_H
#define LED_H

#include "pins.h"

/* LED is active low */
void LED_ON(void)
{
    IOCLR0 = LED;
}

void LED_OFF(void)
{
    IOSET0 = LED;
}

#endif
