//
// Created by L. Jiang <l.jiang.1024@gmail.com> on 2020/12/9.
//

#ifndef ISMDEEP_C_UTILS_GF2_MATRIX_H
#define ISMDEEP_C_UTILS_GF2_MATRIX_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ismdeep-c-utils/array.h>

struct GF2_Matrix {
    size_t row, col;
    uint8_t **data;
};


struct GF2_Matrix *gf2_matrix_create(size_t _row_, size_t _col_);

void gf2_matrix_mul(
        const struct GF2_Matrix *matrix_left, const struct GF2_Matrix *matrix_right,
        struct GF2_Matrix *matrix
);

struct GF2_Matrix *gf2_matrix_mul_func(const struct GF2_Matrix *matrix_left, const struct GF2_Matrix *matrix_right);

void gf2_matrix_copy(const struct GF2_Matrix *matrix_from, struct GF2_Matrix *matrix_to);

struct GF2_Matrix *gf2_matrix_copy_func(const struct GF2_Matrix *matrix);

char *gf2_matrix_dump(const struct GF2_Matrix *matrix);

void gf2_matrix_save(const struct GF2_Matrix *matrix, const char *file_path);

struct GF2_Matrix *gf2_matrix_load(const char *file_path);

#endif //ISMDEEP_C_UTILS_GF2_MATRIX_H
