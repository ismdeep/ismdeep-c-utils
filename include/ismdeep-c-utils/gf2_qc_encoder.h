//
// Created by L. Jiang <l.jiang.1024@gmail.com> on 2020/12/22.
//

#ifndef ISMDEEP_C_UTILS_GF2_QC_ENCODER_H
#define ISMDEEP_C_UTILS_GF2_QC_ENCODER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gf2_matrix.h"

void write_msg(const struct GF2_Matrix *msg, const unsigned char *str, size_t len, size_t start_bit);


void build_systematic_cyclic_g(struct GF2_Matrix *g, struct GF2_Matrix *first_line);


#endif //ISMDEEP_C_UTILS_GF2_QC_ENCODER_H
