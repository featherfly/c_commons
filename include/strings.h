#ifndef _STRINGS_H
#define _STRINGS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <string.h>
#include <stdbool.h>

// ------------------------------------------------------------

/**
 * @brief start is start with source
 * 
 * @param source source str 
 * @param start start str
 * @return true 
 * @return false 
 */
bool is_start_with(char *source, char *start);

// ------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif