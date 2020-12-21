//
// Created by Del Cooper on 2020/12/9.
//

#include <stdio.h>
#include <stdlib.h>

#include <ismdeep-c-utils/gf2_matrix.h>
#include <ismdeep-c-utils/time.h>


void set_random_data(struct GF2_Matrix *matrix) {
    for (size_t i = 0; i < matrix->row; i++) {
        for (size_t j = 0; j < matrix->col; j++) {
            matrix->data[i][j] = random() % 2;
        }
    }
}

void test_mul() {
    srandom(time_us());

    struct GF2_Matrix *matrix_1 = gf2_matrix_create(1, 4);
    struct GF2_Matrix *matrix_2 = gf2_matrix_create(4, 8);

    set_random_data(matrix_1);
    set_random_data(matrix_2);

    printf("%s\n", gf2_matrix_dump(matrix_1));
    printf("%s\n", gf2_matrix_dump(matrix_2));

    struct GF2_Matrix *matrix = gf2_matrix_create(1, 8);
    gf2_matrix_mul(matrix_1, matrix_2, matrix);

    printf("%s\n", gf2_matrix_dump(matrix));
}

void test_save() {
    struct GF2_Matrix *matrix = gf2_matrix_create(4, 8);
    srandom(time_us());
    set_random_data(matrix);
    printf("%s", gf2_matrix_dump(matrix));
    gf2_matrix_save(matrix, "a.mat");
}

void test_load() {
    struct GF2_Matrix *matrix = gf2_matrix_load("a.mat");
    printf("%s", gf2_matrix_dump(matrix));
}

void test_load_and_mul() {
    struct GF2_Matrix *G = gf2_matrix_load("g.mat");
    struct GF2_Matrix *H = gf2_matrix_load("h.mat");

    struct GF2_Matrix *msg = gf2_matrix_create(1, 4);

    srandom(time_us());
    set_random_data(msg);

    struct GF2_Matrix *code = gf2_matrix_mul_func(msg, G);

    code->data[0][0] = 1 - code->data[0][0];

    struct GF2_Matrix *msg2 = gf2_matrix_mul_func(code, H);

    printf("msg:\n%s", gf2_matrix_dump(msg));
    printf("---------------------\n");
    printf("G:\n%s", gf2_matrix_dump(G));
    printf("---------------------\n");
    printf("code:\n%s", gf2_matrix_dump(code));
    printf("---------------------\n");
    printf("H:\n%s", gf2_matrix_dump(H));
    printf("---------------------\n");
    printf("msg2:\n%s", gf2_matrix_dump(msg2));
}



int main() {

//    test_mul();
//    test_save();
//    test_load();

    test_load_and_mul();

    return EXIT_SUCCESS;
}