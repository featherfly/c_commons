#ifndef __FF__MATCH_MAC_H
#define __FF__MATCH_MAC_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief define pow function macro.
 * @code 
 *   // define pow function
 *   POW_FULL_FUN(pow_uint32, uint32_t, uint32_t);
 *   // invoke the defined function
 *   uint32_t result = pow_uint32(2, 2);
 * @endcode
 * @param fn_name function name
 * @param t_x value type (example: uint32_t)
 * @param t_return return value type (example: uint32_t)
 */
#define POW_FULL_FUN(fn_name, t_x, t_return) t_return fn_name(t_x x, uint32_t y) { \
    t_return ret = (t_return) 1;                                                   \
    for (uint32_t i = 0; i < y; i++) {                                             \
        ret *= x;                                                                  \
    }                                                                              \
    return ret;                                                                    \
}

/**
 * @brief define pow function macro.
 * @code 
 *   // define pow function
 *   POW_FUN(pow_uint32, uint32_t);
 *   // invoke the defined function
 *   uint32_t result = pow_uint32(2, 2);
 * @endcode
 * @param fn_name function name
 * @param t_x value type (example: uint32_t)
 */
#define POW_FUN(fn_name, t_x) POW_FULL_FUN(fn_name, t_x, t_x)

// POW_FULL_FUN(pow_int, uint32_t, uint32_t);

// POW_FUN(pow_int, uint32_t);

// POW_FULL_FUN(pow_long, uint64_t, uint64_t);

#ifdef __cplusplus
}
#endif

#endif