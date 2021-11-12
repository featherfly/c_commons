
#include "arrays.h"

int array_copy_char(const char source[], char target[], uint32_t size)
{
  return array_copy_byte((uint8_t *) source, (uint8_t *) target, size);
}

int array_copy_byte(const uint8_t source[], uint8_t target[], uint32_t size)
{  
  int index;
  for(index = 0; index < size; index++) 
  {
    target[index] = source[index];
  } 
  return index;
}

int array_copy_byte2(const uint8_t source[], uint8_t target[], uint32_t start, uint32_t size)
{
  int index;
  for(index = start; index < size + start; index++) 
  {
    target[index - start] = source[index];
  } 
  return index;
}

bool array_equals_byte_char(const uint8_t source[], const char target[], uint32_t size)
{
  bool eq = true;
  for (int i = 0; i < size; i++)
  {
    if (source[i] != target[i]) {
      return false;
    }
  }
  return true;
}
bool array_equals(const char source[], const char target[], uint32_t size)
{
  bool eq = true;
  for (int i = 0; i < size; i++)
  {
    if (source[i] != target[i]) {
      return false;
    }
  }
  return true;
}

int array_set(char target[], const char source[], uint32_t start, uint32_t len)
{
  int index;
  for(index = 0; index < len; index++) 
  {
    target[start + index] = source[index];
  }
  return index;
}