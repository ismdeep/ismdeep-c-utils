//
// Created by L. Jiang <l.jiang.1024@gmail.com> on 2020/12/22.
//

#include "gf2_matrix.h"


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

char *gf2_matrix_dump(const struct GF2_Matrix *matrix) {
    char *ans = (char *) malloc(sizeof(char) * 65535);
    char *tmp = (char *) malloc(sizeof(char) * 65535);
    memset(ans, 0, sizeof(char) * 65535);
    memset(tmp, 0, sizeof(char) * 65535);

    for (size_t i = 0; i < matrix->row; ++i) {
        for (size_t j = 0; j < matrix->col; ++j) {
            sprintf(tmp, "%d ", matrix->data[i][j]);
            strcat(ans, tmp);
        }
        strcat(ans, "\n");
    }
    free(tmp);
    return ans;
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