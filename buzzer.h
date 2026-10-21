#ifndef BUZZER_H
#define BUZZER_H

#include "pins.h"

/* Buzzer is active low */
void BUZZER_ON(void)
{
    IOCLR0 = BUZZER;
}

void BUZZER_OFF(void)
{
    IOSET0 = BUZZER;
}

#endif
