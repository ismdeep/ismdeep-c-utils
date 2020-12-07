//
// Created by L. Jiang <l.jiang.1024@gmail.com> on 2020/12/7.
//

#ifndef ISMDEEP_C_UTILS_INT_H
#define ISMDEEP_C_UTILS_INT_H

#include <stdio.h>

int to_int(const char *str) {
    int n;
    sscanf(str, "%d", &n);
    return n;
}

#endif //ISMDEEP_C_UTILS_INT_H
