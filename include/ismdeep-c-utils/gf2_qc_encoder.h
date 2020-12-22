//
// Created by L. Jiang <l.jiang.1024@gmail.com> on 2020/12/22.
//

#ifndef ISMDEEP_C_UTILS_GF2_QC_ENCODER_H
#define ISMDEEP_C_UTILS_GF2_QC_ENCODER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gf2_matrix.h"


void write_msg(const struct GF2_Matrix *msg, const unsigned char *str, size_t len, size_t start_bit) {
    for (size_t i = 0; i < msg->row; ++i) {
        for (size_t j = 0; j < msg->col; ++j) {
            msg->data[i][j] = 0;
        }
    }

    size_t cursor = start_bit;
    size_t r;

    for (size_t i = 0; i < msg->row; ++i) {
        for (size_t j = 0; j < msg->col; ++j) {
            if (cursor >= len * 8) {
                break;
            }

            r = cursor % 8;
            unsigned char ch = str[cursor / 8];
            msg->data[i][j] = (ch & (1UL << r)) >> r;

            ++cursor;
        }
    }
}


void build_systematic_cyclic_g(struct GF2_Matrix *g, struct GF2_Matrix *first_line) {
    if (g->row * 2 != g->col || g->row != first_line->col) {
        fprintf(stderr, "ERROR: Size error on build_systematic_g().\n");
        return;
    }

    for (size_t i = 0; i < g->row; ++i) {
        for (size_t j = 0; j < g->col; ++j) {
            g->data[i][j] = 0;
        }
    }

    for (size_t i = 0; i < g->row; i++) {
        g->data[i][i] = 1;
    }

    /* Copy first line. */
    for (size_t j = 0; j < g->row; j++) {
        g->data[0][g->row + j] = first_line->data[0][j];
    }

    /* Cyclic Copy */
    for (size_t i = 1; i < g->row; ++i) {
        for (size_t j = g->row; j < g->col - 1; ++j) {
            g->data[i][j] = g->data[i - 1][j + 1];
        }
        g->data[i][g->col - 1] = g->data[i - 1][g->row];
    }
}

#endif //ISMDEEP_C_UTILS_GF2_QC_ENCODER_H
