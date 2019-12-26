//
// Created by ismdeep on 2019/12/25.
//

#ifndef ISMDEEP_C_UTILS_ARRAY_UTILS_H
#define ISMDEEP_C_UTILS_ARRAY_UTILS_H

#include <stdlib.h>

void *create_array(size_t size, size_t sizeof_item) {
    void *arr = malloc(sizeof_item * size);
    return arr;
}

void **create_matrix(size_t rows, size_t cols, size_t sizeof_item) {
    void **arr = (void **) malloc(sizeof(size_t) * rows);
    for (size_t row_id = 0; row_id < rows; ++row_id) {
        arr[row_id] = malloc(sizeof_item * cols);
    }
    return arr;
}

#endif //ISMDEEP_C_UTILS_ARRAY_UTILS_H
