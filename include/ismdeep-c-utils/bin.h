//
// Created by L. Jiang <l.jiang.1024@gmail.com> on 2020/12/7.
//

#ifndef ISMDEEP_C_UTILS_BIN_H
#define ISMDEEP_C_UTILS_BIN_H

#include <stdint.h>
#include <stdlib.h>

int count_bit(uint64_t val) {
    int cnt = 0;
    while (val) {
        cnt += (int) (val & 1UL);
        val >>= 1UL;
    }
    return cnt;
}

#endif //ISMDEEP_C_UTILS_BIN_H
