#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef byte
typedef unsigned char byte;
#endif

#ifndef __cplusplus
#define nullptr NULL
#endif

#ifdef __cplusplus
}
#endif

#endif