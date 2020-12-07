//
// Created by L. Jiang <l.jiang.1024@gmail.com> on 2020/11/2.
//

#ifndef ISMDEEP_COMBINATION_H
#define ISMDEEP_COMBINATION_H

#include <stdint.h>
#include <stdbool.h>
#include "macro_header.h"


/**
 *
 * @param n
 * @param k
 * @param a
 * @return
 */
bool combine_has_next(uint64_t n, uint64_t k, const uint64_t *a) {
    TIMES(i, k) {
        if (a[i] != n - k + i) {
            return true;
        }
    }
    return false;
}

void combine_init(uint64_t k, uint64_t *a) {
    TIMES(i, k) {
        a[i] = i;
    }
}

/**
 *
 * @param n
 * @param k
 * @param a
 */
void combine_next(uint64_t n, uint64_t k, uint64_t *a) {
    uint64_t ceiling = n - 1;
    uint64_t index = k - 1;
    do {
        if (a[index] < ceiling) {
            a[index]++;
            for (uint64_t i = index + 1; i < k; i++) {
                a[i] = a[i - 1] + 1;
            }
            break;
        }
        ceiling = a[index] - 1;
        if (index == 0) {
            break;
        }
        --index;
    } while (true);
}
#endif //ISMDEEP_COMBINATION_H
