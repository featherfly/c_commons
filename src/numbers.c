#include "numbers.h"

#include <stdio.h>

static char _hex_chars[] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

void int32_to_bytes(int32_t i, uint8_t abyte[])
{
    abyte[3] = (uint8_t)(0xff & i);

    abyte[2] = (uint8_t)((0xff00 & i) >> 8);

    abyte[1] = (uint8_t)((0xff0000 & i) >> 16);

    abyte[0] = (uint8_t)((0xff000000 & i) >> 24);
}

void int16_to_bytes(int16_t i, uint8_t abyte[])
{
    abyte[1] = (uint8_t)(0xff & i);

    abyte[0] = (uint8_t)((0xff00 & i) >> 8);
}

void int24_to_bytes(int i, uint8_t abyte[])
{
    abyte[2] = (uint8_t)(0xff & i);

    abyte[1] = (uint8_t)((0xff00 & i) >> 8);

    abyte[0] = (uint8_t)((0xff0000 & i) >> 16);
}
void int8_to_bytes(int8_t i, uint8_t abyte[])
{
    abyte[0] = (uint8_t)(0xff & i);
}
    
void to_hex(uint8_t c, char* hex)
{
    if (c < 16)
    {
        sprintf(hex, "0%c", _hex_chars[c]);
    } else{
        sprintf(hex, "%X", c);
    }
}