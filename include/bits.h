#ifndef __FF__BITS_H
#define __FF__BITS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

#define BIT_GET(mask, index) !((mask & (1UL << index)) == 0)

#define BIT_SET_TRUE(mask, index) *mask |= (1UL << index)

#define BIT_SET_FLASE(mask, index) *mask &= ~(1UL << index)

#define BIT_SET(mask, index, state) if (state) {*mask |= (1UL << index);} else {*mask &= ~(1UL << index);}

/**
 * @brief get bit from mask at index
 * 
 * @param mask bit mask
 * @param index bit index
 * @return true 
 * @return false 
 */
bool bit_get(uint8_t mask, uint8_t index);

/**
 * @brief set bit for mask at index with state
 * 
 * @param mask bit mask
 * @param index bit index
 * @param state bit state
 */
void bit_set(uint8_t* mask, uint8_t index, bool state);

/**
 * @brief set bit for mask at index with state
 * 
 * @param mask bit mask
 * @param index bit index
 * @param state bit state
 * @return the set bit changed bit mask
 */
uint8_t bit_set_new(uint8_t mask, uint8_t index, bool state);



// ------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif