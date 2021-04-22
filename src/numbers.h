#ifndef NUMBERS_H
#define NUMBERS_H

#ifdef __cplusplus
extern "C" {
#endif

void int32_to_bytes(int i, unsigned char abyte[]);

void int24_to_bytes(int i, unsigned char abyte[]);

void int16_to_bytes(int i, unsigned char abyte[]);

void int8_to_bytes(int i, unsigned char abyte[]);

void to_hex(unsigned char c, char* hex);


#ifdef __cplusplus
}
#endif

#endif