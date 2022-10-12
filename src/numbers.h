#ifndef NUMBERS_H
#define NUMBERS_H

#include <stdint.h>
#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

// #define INT_TO_BYTE_FUN(fn_name, t_int, len) void fn_name(t_int i, uint8_t abyte[]) {\
//     int j = 0;                                                                       \
//     for (int i = len - 1 ; i >= 0; i--) {                                            \
//         abyte[i] = (uint8_t)(( t_int )(0xff * pow(256, j)) & i);                     \
//         j++;                                                                         \
//     }                                                                                \
// }                                                                                    \

void int64_to_bytes(int64_t i, uint8_t abyte[]);

void int48_to_bytes(int64_t i, uint8_t abyte[]);

void int32_to_bytes(int32_t i, uint8_t abyte[]);

void int24_to_bytes(int32_t i, uint8_t abyte[]);

void int16_to_bytes(int16_t i, uint8_t abyte[]);

void int8_to_bytes(int8_t i, uint8_t abyte[]);

void to_hex(uint8_t c, char* hex);


#ifdef __cplusplus
}
#endif

#endif