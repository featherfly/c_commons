#include "strings.h"

bool is_start_with(char *target, char *start) {
    return strncmp(target, start, strlen(start)) == 0;
}