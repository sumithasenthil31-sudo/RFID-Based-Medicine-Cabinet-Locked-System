#ifndef RFID_H
#define RFID_H

#include "uart.h"

const char tag1[] = "060067D961D9";
const char tag2[] = "09876543DS21";

char rfid[13];

void RFID_READ(void)
{
    unsigned int count = 0;
    char c;

    while (count < 12)
    {
        c = UART0_RX();

        if (c == '\r' || c == '\n')
        {
            if (count == 12)
                break;

            if (count == 0)
                continue;
        }
        else if ((c >= '0' && c <= '9') ||
                 (c >= 'A' && c <= 'F') ||
                 (c >= 'a' && c <= 'f'))
        {
            rfid[count++] = c;
        }
        else
        {
            count = 0;
        }
    }

    rfid[12] = '\0';
}

int RFID_CHECK(void)
{
    unsigned int i;
    int match1 = 1;
    int match2 = 1;

    for (i = 0; i < 12; i++)
    {
        if (rfid[i] != tag1[i])
            match1 = 0;

        if (rfid[i] != tag2[i])
            match2 = 0;
    }

    return match1 || match2;
}

#endif
