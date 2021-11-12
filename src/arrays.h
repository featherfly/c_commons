#ifndef ARRAYS_H
#define ARRAYS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

bool array_equals_uint8_t_char(const uint8_t source[], const char target[], uint32_t len);

bool array_equals(const char source[], const char target[], uint32_t len);

/**
 * @param source 复制源 
 * @param target 复制目标
 * @param size 复制数量
 */
int array_copy_uint8_t(const uint8_t source[], uint8_t target[], uint32_t size);

int array_copy_char(const char source[], char target[], uint32_t size);

/**
 * @param source 复制源 
 * @param target 复制目标
 * @param start 复制源开始索引（包含）
 * @param size 复制数量
 */
int array_copy_uint8_t2(const uint8_t source[], uint8_t target[], uint32_t start, uint32_t size);

/**
 * @param target 设置目标
 * @param source 设置源 
 * @param start 目标起始位置
 * @param len 源数组长度
 */
int array_set(char target[], const char source[], uint32_t start, uint32_t len);

#ifdef __cplusplus
}
#endif

#endif