#ifndef NUMBERS_H
#define NUMBERS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void int32_to_bytes(int32_t i, uint8_t abyte[]);

void int24_to_bytes(int i, uint8_t abyte[]);

void int16_to_bytes(int16_t i, uint8_t abyte[]);

void int8_to_bytes(int8_t i, uint8_t abyte[]);

void to_hex(uint8_t c, char* hex);


#ifdef __cplusplus
}
#endif

#endif