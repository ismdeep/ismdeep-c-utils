//
// Created by L. Jiang on 2020/12/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <ismdeep-c-utils/gf2_qc_encoder.h>

int main() {
    struct GF2_Matrix *msg = gf2_matrix_create(1, 32);
    write_msg(msg, "\xFFHello World.", 0);
    printf("%s\n", gf2_matrix_dump(msg));

    struct GF2_Matrix *G = gf2_matrix_create(32, 64);
    build_systematic_cyclic_g(G, msg);

    printf("%s\n", gf2_matrix_dump(G));

    return EXIT_SUCCESS;
}