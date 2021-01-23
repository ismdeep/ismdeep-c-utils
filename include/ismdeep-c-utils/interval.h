//
// Created by L. Jiang on 2021/1/23.
//

#ifndef ISMDEEP_C_UTILS_INTERVAL_H
#define ISMDEEP_C_UTILS_INTERVAL_H

#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#include "macro_header.h"

struct Interval {
    uint64_t min_val;
    uint64_t max_val;
    uint64_t cursor_min_val;
    uint64_t cursor_max_val;
    pthread_mutex_t *mutex_pointer;
};

struct Interval *interval_create(uint64_t _min_val_, uint64_t _max_val_, pthread_mutex_t *_mutex_pointer_) {
    struct Interval *interval = (struct Interval *) malloc(sizeof(struct Interval) * 1);
    interval->min_val = _min_val_;
    interval->max_val = _max_val_;
    interval->cursor_min_val = interval->min_val;
    interval->cursor_max_val = interval->max_val;
    interval->mutex_pointer = _mutex_pointer_;
    return interval;
}

bool interval_get(struct Interval *interval, uint64_t *left_val, uint64_t *right_val, uint64_t interval_size) {
    if (interval->mutex_pointer != NULL) {
        pthread_mutex_lock(interval->mutex_pointer);
    }

    if (interval->cursor_min_val > interval->cursor_max_val) {
        if (interval->mutex_pointer != NULL) {
            pthread_mutex_unlock(interval->mutex_pointer);
        }
        return false;
    }

    uint64_t shift_result = MIN(interval->cursor_min_val + interval_size - 1, interval->max_val);
    *left_val = interval->cursor_min_val;
    *right_val = shift_result;
    interval->cursor_min_val = shift_result + 1;

    if (interval->mutex_pointer != NULL) {
        pthread_mutex_unlock(interval->mutex_pointer);
    }
    return true;
}




#endif //ISMDEEP_C_UTILS_INTERVAL_H
