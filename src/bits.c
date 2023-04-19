#include "bits.h"

bool bit_get(uint8_t value, uint8_t index) {
    return BIT_GET(value, index);
}

void bit_set(uint8_t* value, uint8_t index, bool state) {
    BIT_SET(value, index, state);
}

uint8_t bit_set_new(uint8_t value, uint8_t index, bool state) {
    if (state) {
        return value | (1UL << index);
    } else {
        return value & ~(1UL << index);
    }
}