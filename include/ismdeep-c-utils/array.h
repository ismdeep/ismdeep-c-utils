//
// Created by L. Jiang <l.jiang.1024@gmail.com> on 2019/12/25.
//

#ifndef ISMDEEP_C_UTILS_ARRAY_UTILS_H
#define ISMDEEP_C_UTILS_ARRAY_UTILS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

void *create_array(size_t size, size_t sizeof_item);

char *array_to_str(int *arr, size_t size);

void **create_matrix(size_t rows, size_t cols, size_t sizeof_item);

void *create_1d_arr(size_t size, size_t sizeof_item);

void **create_2d_arr(size_t rows, size_t cols, size_t sizeof_item);

#endif //ISMDEEP_C_UTILS_ARRAY_UTILS_H
