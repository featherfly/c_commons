#ifndef _STRINGS_H
#define _STRINGS_H

#ifdef __cplusplus
extern "C" {
#endif

// ------------------------------------------------------------

#include <stdarg.h>
#include <stdbool.h>
#include <string.h>

/**
 * @brief declare new string variate.
 * @code
 *   // define new string variate
 *   STR_NEW(msg, 10);
 *   // use the defined variate
 *   printf("%s", msg);
 * @endcode
 * @param var_name variate name
 * @param str_len string length
 */
#define STR_NEW(var_name, str_len) \
    char var_name[str_len + 1];    \
    var_name[str_len] = '\0';

/**
 * @brief declare new string variate clone from another str.
 * @code
 *   // define clone a new string variate
 *   STR_NCLONE_NEW(cloneStr, "source string", 5);
 *   // use the defined variate
 *   printf("%s", cloneStr);
 * @endcode
 * @param var_name variate name
 * @param str_src clone source string
 * @param clone_len clone length
 */
#define STR_NCLONE_NEW(var_name, str_src, clone_len) \
    char var_name[clone_len + 1];                    \
    var_name[clone_len] = '\0';                      \
    strncpy(var_name, str_src, clone_len);

/**
 * @brief vsprintf with function ... argus
 * @code
 *   int len = 0;
 *   // the variate named var_name must be declared behind
 *   VSPRINTF_USE(len, buff, format, last_arg_name);
 *   printf("VSPRINTF_USE  \n%s  \nlen %d\n", buff, len);
 * @endcode
 * @param var_name variate name
 * @param str_src clone source string
 * @param clone_len clone length
 */
#define VSPRINTF_USE(var_name, str_dest, str_format, last_arg) \
    ({                                                         \
        va_list list;                                          \
        va_start(list, last_arg);                              \
        var_name = vsprintf(str_dest, str_format, list);       \
        va_end(list);                                          \
    });

/**
 * @brief vsprintf with function ... argus
 * @code
 *   // no variate named len is defined, macro will auto define variate with
 * var_name VSPRINTF_NEW(len, buff, format, last_arg_name); printf("VSPRINTF_NEW
 * \n%s  \nlen %d\n", buff, len);
 * @endcode
 * @param var_name variate name
 * @param str_dest str dest
 * @param str_format str format
 * @param last_arg function last argu name, behind ...
 */
#define VSPRINTF_NEW(var_name, str_dest, str_format, last_arg) \
    int var_name = 0;                                          \
    VSPRINTF_USE(var_name, str_dest, str_format, last_arg);

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------
// -- gcc clang define
#if defined(__GNUC__) || defined(__clang__)

/**
 * @brief declare string variate.
 *   only work with gcc,clang
 * @code
 *   // use this macro
 *   char* str = STR(10);
 * @endcode
 * @param str_len string length
 * @return string variate
 */
#define STR(str_len)           \
    ({                         \
        char str[str_len + 1]; \
        str[str_len] = '\0';   \
        str;                   \
    });

/**
 * @brief clone string.
 *   only work with gcc,clang
 * @code
 *   // use this macro
 *   char* str = STR_NCLONE("source string", 5);
 * @endcode
 * @param str_src clone source string
 * @param clone_len clone length
 * @return cloned string variate
 */
#define STR_NCLONE(str_src, clone_len)    \
    ({                                    \
        char str[clone_len + 1];          \
        str[clone_len] = '\0';            \
        strncpy(str, str_src, clone_len); \
        str;                              \
    });

/**
 * @brief vsprintf with function ... argus
 * @code
 *   int len = VSPRINTF(buff, format, last_arg_name);
 *   printf("VSPRINTF  \n%s  \nlen %d\n", buff, len);
 * @endcode
 * @param var_name variate name
 * @param str_src clone source string
 * @param clone_len clone length
 */
#define VSPRINTF(str_dest, str_format, last_arg)    \
    ({                                              \
        int len = 0;                                \
        va_list list;                               \
        va_start(list, last_arg);                   \
        len = vsprintf(str_dest, str_format, list); \
        va_end(list);                               \
        len;                                        \
    });

// -- endif gcc clang define
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------
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