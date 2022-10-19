#ifndef _STRINGS_H
#define _STRINGS_H

#ifdef __cplusplus
extern "C" {
#endif

// ------------------------------------------------------------

#include <string.h>
#include <stdbool.h>

/**
 * @brief declare string variate.
 * @code 
 *   // define string variate
 *   STRING(msg, 10);
 *   // use the defined variate
 *   printf("%s", msg);
 * @endcode
 * @param var_name variate name
 * @param str_len string length
 */
#define STRING(var_name, str_len) char var_name[str_len + 1];var_name[str_len] = '\0';

/**
 * @brief declare string variate.
 * @code 
 *   // define clone string variate
 *   STRING_NCLONE(cloneStr, "source string", 5);
 *   // use the defined variate
 *   printf("%s", cloneStr);
 * @endcode
 * @param var_name variate name
 * @param str_src clone source string
 * @param clone_len clone length
 */
#define STRING_NCLONE(var_name, str_src, clone_len) char var_name[clone_len + 1];var_name[clone_len] = '\0';strncpy(var_name, str_src, clone_len);

#if defined(__GNUC__) || defined(__clang__)

/**
 * @brief declare string variate.
 *   only work with gcc,clang
 * @code 
 *   // use this macro
 *   char* str = STR(10);
 * @endcode
 * @param str_len string length
 */
#define STR(str_len) ({char str[str_len + 1];str[str_len] = '\0';str;});

/**
 * @brief clone string.
 *   only work with gcc,clang
 * @code 
 *   // use this macro
 *   char* str = STR_NCLONE("source string", 5);
 * @endcode
 * @param str_src clone source string
 * @param clone_len clone length
 */
#define STR_NCLONE(str_src, clone_len) ({char str[clone_len + 1];str[clone_len] = '\0';strncpy(str, str_src, clone_len);str;});

#endif

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