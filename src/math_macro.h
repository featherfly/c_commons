#ifndef MATCH_MAC_H
#define MATCH_MAC_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define POW_FULL_FUN(fn_name, t_x, t_return) t_return fn_name(t_x x, uint32_t y) { \
    t_return ret = (t_return) 1;                                                   \
    for (uint32_t i = 0; i < y; i++) {                                             \
        ret *= x;                                                                  \
    }                                                                              \
    return ret;                                                                    \
}

#define POW_FUN(fn_name, t_x) POW_FULL_FUN(fn_name, t_x, t_x)

// POW_FULL_FUN(pow_int, uint32_t, uint32_t);

// POW_FUN(pow_int, uint32_t);

POW_FULL_FUN(pow_long, uint64_t, uint64_t);

#ifdef __cplusplus
}
#endif

#endif