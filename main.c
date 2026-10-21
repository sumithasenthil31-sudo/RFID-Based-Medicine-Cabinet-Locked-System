#include <LPC21xx.h>
#include "pins.h"
#include "delay.h"
#include "uart.h"
#include "rfid.h"
#include "lcd.h"
#include "motor.h"
#include "led.h"
#include "buzzer.h"

int main(void)
{
    PINSEL0 &= ~0xFFFF0000;
    PINSEL1 &= ~0x00003FFF;

    IODIR0 |= LCD_D | RS | E | MOTOR_IN1 | MOTOR_IN2 | LED | BUZZER;
    IODIR0 &= ~SWITCH;

    MOTOR_STOP();
    LED_OFF();
    BUZZER_OFF();
    UART0_INIT();
    LCD_INIT();

    LCD_STATUS("Hospital Cabinet", "RFID System");
    delay_milliseconds(2000);

    while (1)
    {
        LCD_STATUS("Scan RFID Card", "Waiting...");
        RFID_READ();

        if (RFID_CHECK())
        {
            BUZZER_OFF();
            LCD_STATUS("Authorized ID", "Access Granted");
            delay_milliseconds(1000);

            LED_ON();

            LCD_STATUS("LED ON", "Motor ON-Opening");

            MOTOR_OPEN();
            delay_milliseconds(5000);
            MOTOR_STOP();

            LED_OFF();

            LCD_STATUS("Cabinet Open", "Press Switch");

            while (IOPIN0 & SWITCH);

            delay_milliseconds(50);

            if (!(IOPIN0 & SWITCH))
            {
                LCD_STATUS("Motor ON", "Closing...");

                MOTOR_CLOSE();
                delay_milliseconds(5000);
                MOTOR_STOP();

                LCD_STATUS("Cabinet Closed", "Scan RFID Card");
                delay_milliseconds(1500);
            }

            while (!(IOPIN0 & SWITCH));

            delay_milliseconds(50);
        }
        else
        {
            MOTOR_STOP();
            LED_ON();

            LCD_STATUS("Unauthorized ID", "Buzzer ON");

            BUZZER_ON();
            delay_milliseconds(1000);
            BUZZER_OFF();
            delay_milliseconds(1000);
        }
    }
}
