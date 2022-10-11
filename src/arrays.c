
#include "arrays.h"

ARRAY_EQUALS_FUN(array_equals_uint32, uint32_t, uint32_t);

ARRAY_EQUALS_FUN(array_equals_uint8_char, uint8_t, char);

// bool array_equals_uint8_char(const uint8_t source[], const char target[],
//                              uint32_t size) {
//     bool eq = true;
//     for (int i = 0; i < size; i++) {
//         if (source[i] != target[i]) {
//             return false;
//         }
//     }
//     return true;
// }

bool array_equals(const char source[], const char target[], uint32_t size) {
    bool eq = true;
    for (int i = 0; i < size; i++) {
        if (source[i] != target[i]) {
            return false;
        }
    }
    return true;
}

int array_copy_uint8(const uint8_t source[], uint8_t target[], uint32_t size) {
    int index;
    for (index = 0; index < size; index++) {
        target[index] = source[index];
    }
    return index;
}

int array_copy_char(const char source[], char target[], uint32_t size) {
    return array_copy_uint8((uint8_t *)source, (uint8_t *)target, size);
}

int array_copy_range_uint8(const uint8_t source[], uint8_t target[],
                           uint32_t start, uint32_t size) {
    int index;
    for (index = start; index < size + start; index++) {
        target[index - start] = source[index];
    }
    return index;
}

int array_set(char target[], const char source[], uint32_t start,
              uint32_t len) {
    int index;
    for (index = 0; index < len; index++) {
        target[start + index] = source[index];
    }
    return index;
}