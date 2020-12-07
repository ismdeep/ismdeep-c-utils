//
// Created by L. Jiang <l.jiang.1024@gmail.com> on 2019/12/26.
//

#ifndef ISMDEEP_C_UTILS_MACRO_HEADER_H
#define ISMDEEP_C_UTILS_MACRO_HEADER_H

#include <stdint.h>

#define TIMES(id, size) for(uint64_t id = 0; id < (size); ++id)

#define MIN(x,y) (((x) < (y) ? (x) : (y)))
#define MAX(x,y) (((x) > (y) ? (x) : (y)))

#endif //ISMDEEP_C_UTILS_MACRO_HEADER_H
