//
// Created by L. Jiang <l.jiang.1024@gmail.com> on 2019/12/25.
//

#ifndef ISMDEEP_C_UTILS_ARRAY_UTILS_H
#define ISMDEEP_C_UTILS_ARRAY_UTILS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

void *create_array(size_t size, size_t sizeof_item) {
    void *arr = malloc(sizeof_item * size);
    return arr;
}

char *array_to_str(int *arr, size_t size) {
    char *str = (char *) create_array(65535, sizeof(char));
    char buf[20];
    strcpy(str, "");
    strcat(str, "[");
    for (size_t i = 0; i < size; i++) {
        if (i) {
            strcat(str, ",");
        }
        sprintf(buf, "%d", arr[i]);
        strcat(str, buf);
    }
    strcat(str, "]");
    return str;
}

void **create_matrix(size_t rows, size_t cols, size_t sizeof_item) {
    void **arr = (void **) malloc(sizeof(size_t) * rows);
    size_t row_id;
    for (row_id = 0; row_id < rows; ++row_id) {
        arr[row_id] = malloc(sizeof_item * cols);
    }
    return arr;
}

void *create_1d_arr(size_t size, size_t sizeof_item) {
    void *arr = malloc(sizeof_item * size);
    return arr;
}

void **create_2d_arr(size_t rows, size_t cols, size_t sizeof_item) {
    void **arr = (void **) malloc(sizeof(size_t) * rows);
    for (size_t row_id = 0; row_id < rows; ++row_id) {
        arr[row_id] = malloc(sizeof_item * cols);
    }
    return arr;
}

#endif //ISMDEEP_C_UTILS_ARRAY_UTILS_H
