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

struct GF2_Matrix *gf2_matrix_init(size_t _row_, size_t _col_) {
    struct GF2_Matrix *matrix = (struct GF2_Matrix *) malloc(sizeof(struct GF2_Matrix) * 1);
    matrix->row = _row_;
    matrix->col = _col_;
    matrix->data = (uint8_t **) create_matrix(_row_, _col_, sizeof(uint8_t));
    for (size_t i = 0; i < _row_; ++i) {
        for (size_t j = 0; j < _col_; ++j) {
            matrix->data[i][j] = 0;
        }
    }
    return matrix;
}

struct GF2_Matrix *gf2_matrix_mul(const struct GF2_Matrix *matrix_left, const struct GF2_Matrix *matrix_right) {
    if (matrix_left->col != matrix_right->row) {
        fprintf(stderr, "ERROR: gf2_matrix_mul(), matrix_left->col != matrix_right->row\n");
        return NULL;
    }

    struct GF2_Matrix *matrix = gf2_matrix_init(matrix_left->row, matrix_right->col);

    for (size_t i = 0; i < matrix->row; ++i) {
        for (size_t j = 0; j < matrix->col; ++j) {

            uint64_t tmp = 0;
            for (size_t k = 0; k < matrix_left->row; k++) {
                tmp += matrix_left->data[i][k] * matrix_right->data[k][j];
            }

            matrix->data[i][j] = tmp & 1ULL;
        }
    }

    return matrix;
}

void gf2_matrix_display(const struct GF2_Matrix *matrix) {
    for (size_t i = 0; i < matrix->row; ++i) {
        for (size_t j = 0; j < matrix->col; ++j) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

#endif //ISMDEEP_C_UTILS_GF2_MATRIX_H
