#ifndef __FF__NUMBERS_H
#define __FF__NUMBERS_H

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

/**
 * @brief int8_t to uint8_t array[8]
 * 
 * @param value the value to convert
 * @param bytes the byte array, length 8
 */
void int64_to_bytes(int64_t value, uint8_t bytes[]);

/**
 * @brief int8_t to uint8_t array[6]
 * 
 * @param value the value to convert
 * @param bytes the byte array, length 6
 */
void int48_to_bytes(int64_t value, uint8_t bytes[]);

/**
 * @brief int8_t to uint8_t array[4]
 * 
 * @param value the value to convert
 * @param bytes the byte array, length 4
 */
void int32_to_bytes(int32_t value, uint8_t bytes[]);

/**
 * @brief int8_t to uint8_t array[3]
 * 
 * @param value the value to convert
 * @param bytes the byte array, length 3
 */
void int24_to_bytes(int32_t value, uint8_t bytes[]);

/**
 * @brief int8_t to uint8_t array[2]
 * 
 * @param value the value to convert
 * @param bytes the byte array, length 2
 */
void int16_to_bytes(int16_t value, uint8_t bytes[]);

/**
 * @brief int8_t to uint8_t array[1]
 * 
 * @param value the value to convert
 * @param bytes the byte array, length 1
 */
void int8_to_bytes(int8_t value, uint8_t bytes[]);

void to_hex(uint8_t c, char* hex);


#ifdef __cplusplus
}
#endif

#endif