#ifndef LCD_H
#define LCD_H

#include "pins.h"
#include "delay.h"

void LCD_COMMAND(unsigned char c)
{
    IOCLR0 = LCD_D;
    IOSET0 = ((unsigned int)c << 8) & LCD_D;
    IOCLR0 = RS;
    IOSET0 = E;

    delay_milliseconds(1);

    IOCLR0 = E;

    if (c == 0x01 || c == 0x02)
        delay_milliseconds(2);
    else
        delay_milliseconds(1);
}

void LCD_DATA(unsigned char d)
{
    IOCLR0 = LCD_D;
    IOSET0 = ((unsigned int)d << 8) & LCD_D;
    IOSET0 = RS;
    IOSET0 = E;

    delay_milliseconds(1);

    IOCLR0 = E;

    delay_milliseconds(1);
}

void LCD_INIT(void)
{
    IODIR0 |= LCD_D | RS | E;
    IOCLR0 = LCD_D | RS | E;

    delay_milliseconds(20);

    LCD_COMMAND(0x38);
    LCD_COMMAND(0x0C);
    LCD_COMMAND(0x06);
    LCD_COMMAND(0x01);

    delay_milliseconds(2);
}

void LCD_STRING(char *s)
{
    while (*s)
        LCD_DATA(*s++);
}

void LCD_LINE2(void)
{
    LCD_COMMAND(0xC0);
}

void LCD_STATUS(char *line1, char *line2)
{
    LCD_COMMAND(0x01);
    LCD_STRING(line1);
    LCD_LINE2();
    LCD_STRING(line2);
}

#endif
