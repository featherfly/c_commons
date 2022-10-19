#include "numbers.h"

#include <stdio.h>

static char _hex_chars[] = {'0', '1', '2', '3', '4', '5', '6', '7',
                            '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

// INT_TO_BYTE_FUN(int64_to_bytes, int64_t, 8);

void int64_to_bytes(int64_t i, uint8_t abyte[]) {
    abyte[7] = (uint8_t)(0xff & i);

    abyte[6] = (uint8_t)((0xff00 & i) >> 8);

    abyte[5] = (uint8_t)((0xff0000 & i) >> 16);

    abyte[4] = (uint8_t)((0xff000000 & i) >> 24);

    abyte[3] = (uint8_t)((0xff00000000 & i) >> 32);

    abyte[2] = (uint8_t)((0xff0000000000 & i) >> 40);

    abyte[1] = (uint8_t)((0xff000000000000 & i) >> 48);

    abyte[0] = (uint8_t)((0xff00000000000000 & i) >> 56);
}

void int48_to_bytes(int64_t i, uint8_t abyte[]) {
    abyte[5] = (uint8_t)(0xff & i);

    abyte[4] = (uint8_t)((0xff00 & i) >> 8);

    abyte[3] = (uint8_t)((0xff0000 & i) >> 16);

    abyte[2] = (uint8_t)((0xff000000 & i) >> 24);

    abyte[1] = (uint8_t)((0xff00000000 & i) >> 32);

    abyte[0] = (uint8_t)((0xff0000000000 & i) >> 40);
}

void int32_to_bytes(int32_t i, uint8_t abyte[]) {
    abyte[3] = (uint8_t)(0xff & i);

    abyte[2] = (uint8_t)((0xff00 & i) >> 8);

    abyte[1] = (uint8_t)((0xff0000 & i) >> 16);

    abyte[0] = (uint8_t)((0xff000000 & i) >> 24);
}

void int24_to_bytes(int32_t i, uint8_t abyte[]) {
    abyte[2] = (uint8_t)(0xff & i);

    abyte[1] = (uint8_t)((0xff00 & i) >> 8);

    abyte[0] = (uint8_t)((0xff0000 & i) >> 16);
}

void int16_to_bytes(int16_t i, uint8_t abyte[]) {
    abyte[1] = (uint8_t)(0xff & i);

    abyte[0] = (uint8_t)((0xff00 & i) >> 8);
}

void int8_to_bytes(int8_t i, uint8_t abyte[]) {
    abyte[0] = (uint8_t)(0xff & i);
}

void to_hex(uint8_t c, char* hex) {
    if (c < 16) {
        sprintf(hex, "0%c", _hex_chars[c]);
    } else {
        sprintf(hex, "%X", c);
    }
}