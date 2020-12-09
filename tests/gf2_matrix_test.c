//
// Created by Del Cooper on 2020/12/9.
//

#include <stdio.h>
#include <stdlib.h>

#include <ismdeep-c-utils/gf2_matrix.h>

int main() {

    struct GF2_Matrix *matrix_1 = gf2_matrix_init(1, 4);
    struct GF2_Matrix *matrix_2 = gf2_matrix_init(4, 8);

    matrix_1->data[0][0] = 1;

    printf("%s\n", gf2_matrix_dump(matrix_1));
    printf("%s\n", gf2_matrix_dump(matrix_2));

    struct GF2_Matrix *matrix = gf2_matrix_mul(matrix_1, matrix_2);

    printf("%s\n", gf2_matrix_dump(matrix));

    return EXIT_SUCCESS;
}