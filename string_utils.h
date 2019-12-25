//
// Created by ismdeep on 2019/12/25.
//

#ifndef ISMDEEP_C_UTILS_STRING_UTILS_H
#define ISMDEEP_C_UTILS_STRING_UTILS_H

#include <stdlib.h>

char *int_to_string(int val) {
    char *str = (char *) malloc(256 * sizeof(char));
    sprintf(str, "%d", val);
    return str;
}

int string_to_int(const char *str) {
    int val;
    sscanf(str,"%d", &val);
    return val;
}

#endif //ISMDEEP_C_UTILS_STRING_UTILS_H
