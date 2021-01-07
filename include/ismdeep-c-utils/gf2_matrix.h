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

struct GF2_Matrix *gf2_matrix_create(size_t _row_, size_t _col_) {
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

void gf2_matrix_destroy(struct GF2_Matrix *matrix) {
    for (size_t i = 0; i < matrix->row; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

struct GF2_Matrix *gf2_matrix_eye(size_t size) {
    struct GF2_Matrix *matrix = gf2_matrix_create(size, size);
    for (size_t i = 0; i < size; i++) {
        matrix->data[i][i] = 1;
    }
    return matrix;
}

struct GF2_Matrix *gf2_matrix_concat(struct GF2_Matrix *left, struct GF2_Matrix *right) {
    if (left->row != right->row) {
        fprintf(stderr, "ERROR: Size error on gf2_matrix_concat()\n");
        return NULL;
    }

    struct GF2_Matrix *matrix = gf2_matrix_create(left->row, left->col + right->col);

    for (size_t i = 0; i < left->row; i++) {
        for (size_t j = 0; j < left->col; j++) {
            matrix->data[i][j] = left->data[i][j];
        }
        for (size_t j = 0; j < right->col; j++) {
            matrix->data[i][j + left->col] = right->data[i][j];
        }
    }

    return matrix;
}

void gf2_matrix_transport(struct GF2_Matrix *m1, struct GF2_Matrix *m2) {
    for (size_t i = 0; i < m1->row; ++i) {
        for (size_t j = 0; j < m1->col; ++j) {
            m2->data[j][i] = m1->data[i][j];
        }
    }
}

struct GF2_Matrix *gf2_matrix_transport_func(struct GF2_Matrix *m1) {
    struct GF2_Matrix *matrix = gf2_matrix_create(m1->col, m1->row);
    gf2_matrix_transport(m1, matrix);
    return matrix;
}

void gf2_matrix_mul(
        const struct GF2_Matrix *matrix_left, const struct GF2_Matrix *matrix_right,
        struct GF2_Matrix *matrix
) {
    if (matrix_left->col != matrix_right->row) {
        fprintf(stderr, "ERROR: gf2_matrix_mul(), matrix_left->col != matrix_right->row\n");
        return;
    }

    for (size_t i = 0; i < matrix->row; ++i) {
        for (size_t j = 0; j < matrix->col; ++j) {

            uint64_t tmp = 0;
            for (size_t k = 0; k < matrix_left->col; k++) {
                tmp += matrix_left->data[i][k] * matrix_right->data[k][j];
            }

            matrix->data[i][j] = tmp & 1ULL;
        }
    }
}

struct GF2_Matrix *gf2_matrix_mul_func(const struct GF2_Matrix *matrix_left, const struct GF2_Matrix *matrix_right) {
    struct GF2_Matrix *matrix = gf2_matrix_create(matrix_left->row, matrix_right->col);
    gf2_matrix_mul(matrix_left, matrix_right, matrix);
    return matrix;
}

void gf2_matrix_add(const struct GF2_Matrix *matrix_left, const struct GF2_Matrix *matrix_right, struct GF2_Matrix *matrix) {
    if (!(
            matrix_left->row == matrix_right->row
            && matrix_left->col == matrix_right->col
            && matrix_left->row == matrix->row
            && matrix_left->col == matrix->col
            )) {
        fprintf(stderr, "ERROR: Error matrix size on gf2_matrix_add()\n");
        return;
    }

    for (size_t i = 0; i < matrix->row; ++i) {
        for (size_t j = 0; j < matrix->col; ++j) {
            matrix->data[i][j] = (matrix_left->data[i][j] + matrix_right->data[i][j]) % 2;
        }
    }
}

struct GF2_Matrix *gf2_matrix_add_func(const struct GF2_Matrix *matrix_left, const struct GF2_Matrix *matrix_right) {
    struct GF2_Matrix *matrix = gf2_matrix_create(matrix_left->row, matrix_left->col);
    gf2_matrix_add(matrix_left, matrix_right, matrix);
    return matrix;
}

void gf2_matrix_copy(const struct GF2_Matrix *matrix_from, struct GF2_Matrix *matrix_to) {
    if (matrix_from->row != matrix_to->row || matrix_from->col != matrix_to->col) {
        fprintf(stderr, "ERROR: gf2_matrix_copy() with wrong size.");
        return;
    }
    for (size_t i = 0; i < matrix_from->row; i++) {
        for (size_t j = 0; j < matrix_from->col; j++) {
            matrix_to->data[i][j] = matrix_from->data[i][j];
        }
    }
}

struct GF2_Matrix *gf2_matrix_copy_func(const struct GF2_Matrix *matrix) {
    struct GF2_Matrix *matrix_copied = gf2_matrix_create(matrix->row, matrix->col);
    gf2_matrix_copy(matrix, matrix_copied);
    return matrix_copied;
}

char *gf2_matrix_dump_core(const struct GF2_Matrix *matrix, char ch0, char ch1) {
    char *ans = (char *) malloc(sizeof(char) * 65535);
    char *tmp = (char *) malloc(sizeof(char) * 65535);
    memset(ans, 0, sizeof(char) * 65535);
    memset(tmp, 0, sizeof(char) * 65535);

    for (size_t i = 0; i < matrix->row; ++i) {
        for (size_t j = 0; j < matrix->col; ++j) {
            sprintf(tmp, "%c ", matrix->data[i][j] ?  ch1 : ch0);
            strcat(ans, tmp);
        }
        strcat(ans, "\n");
    }
    free(tmp);
    return ans;
}

char *gf2_matrix_dump(const struct GF2_Matrix *matrix) {
    return gf2_matrix_dump_core(matrix, '0', '1');
}

void gf2_matrix_save(const struct GF2_Matrix *matrix, const char *file_path) {
    FILE *fp = fopen(file_path, "w");
    fprintf(fp, "%ld %ld\n", matrix->row, matrix->col);
    char *str = gf2_matrix_dump(matrix);
    fprintf(fp, "%s", str);
    free(str);
    fclose(fp);
    fp = NULL;
}

struct GF2_Matrix *gf2_matrix_load(const char *file_path) {
    FILE *fp = fopen(file_path, "r");
    if (fp == NULL) {
        fprintf(stderr, "ERROR: Failed to open file. [%s]\n", file_path);
        return NULL;
    }

    size_t row, col;

    fscanf(fp, "%ld %ld", &row, &col);
    int tmp;
    struct GF2_Matrix *matrix = gf2_matrix_create(row, col);
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            fscanf(fp, "%d", &tmp);
            matrix->data[i][j] = tmp;
        }
    }

    fclose(fp);
    fp = NULL;
    return matrix;
}

bool gf2_matrix_is_identity(const struct GF2_Matrix *matrix) {
    if (matrix->row <= 0 || matrix->row != matrix->col) {
        return false;
    }

    for (size_t i = 0; i < matrix->row; ++i) {
        for (size_t j = 0; j < matrix->col; ++j) {
            if (i == j && matrix->data[i][j] != 1) {
                return false;
            }
            if (i != j && matrix->data[i][j] != 0) {
                return false;
            }
        }
    }

    return true;
}

#endif //ISMDEEP_C_UTILS_GF2_MATRIX_H
