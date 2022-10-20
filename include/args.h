#ifndef _STRINGS_H
#define _STRINGS_H

#ifdef __cplusplus
extern "C" {
#endif

// ------------------------------------------------------------

#include <stdarg.h>
#include <string.h>

/**
 * @brief vsscanf with function ... argus
 * @code
 *   int len = 0;
 *   // the variate named var_name must be declared behind
 *   VSSCANF_USE(len, buff, format, last_arg_name);
 *   printf("VSSCANF_USE  \n%s  \nlen %d\n", buff, len);
 * @endcode
 * @param var_name variate name
 * @param str_src clone source string
 * @param clone_len clone length
 */
#define VSSCANF_USE(var_name, str_src, str_format, last_arg) \
    ({                                                        \
        va_list list;                                         \
        va_start(list, last_arg);                             \
        var_name = vsscanf(str_src, str_format, list);       \
        va_end(list);                                         \
    });

/**
 * @brief vsscanf with function ... argus
 * @code
 *   // no variate named len is defined, macro will auto define variate with
 *   var_name VSSCANF_NEW(len, buff, format, last_arg_name);
 *   printf("VSSCANF_NEW\n%s  \nlen %d\n", buff, len);
 * @endcode
 * @param var_name variate name
 * @param str_src str dest
 * @param str_format str format
 * @param last_arg function last argu name, behind ...
 */
#define VSSCANF_NEW(var_name, str_src, str_format, last_arg) \
    int var_name = 0;                                         \
    VSSCANF_USE(var_name, str_src, str_format, last_arg);

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------
// -- gcc clang define
#if defined(__GNUC__) || defined(__clang__)

/**
 * @brief vsscanf with function ... argus
 * @code
 *   VSSCANF(str_value, format, last_arg_name);
 *   printf("VSSCANF  %s  \nlen %d\n, arg0 %d, arg1 %d", str_value, len, arg0,
 * arg1);
 * @endcode
 * @param var_name variate name
 * @param str_src clone source string
 * @param clone_len clone length
 */
#define VSSCANF(str_src, str_format, last_arg)              \
    ({                                                      \
        int len = 0;                                        \
        va_list list;                                       \
        va_start(list, last_arg);                           \
        len = vsscanf((char *)(str_src), str_format, list); \
        va_end(list);                                       \
        len;                                                \
    });

// -- endif gcc clang define
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------
#endif

// ------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif