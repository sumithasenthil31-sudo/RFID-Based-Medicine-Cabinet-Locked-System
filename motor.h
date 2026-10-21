#ifndef MOTOR_H
#define MOTOR_H

#include "pins.h"

void MOTOR_OPEN(void)
{
    IOCLR0 = MOTOR_IN2;
    IOSET0 = MOTOR_IN1;
}

void MOTOR_CLOSE(void)
{
    IOCLR0 = MOTOR_IN1;
    IOSET0 = MOTOR_IN2;
}

void MOTOR_STOP(void)
{
    IOCLR0 = MOTOR_IN1 | MOTOR_IN2;
}

#endif
