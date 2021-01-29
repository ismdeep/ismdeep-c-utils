//
// Created by L. Jiang <l.jiang.1024@gmail.com> on 2019/12/26.
//

#ifndef ISMDEEP_C_UTILS_MACRO_HEADER_H
#define ISMDEEP_C_UTILS_MACRO_HEADER_H

#include <stdint.h>

#define LOOP(type, id, size) for(type id = 0; id < (size); ++id)
#define TIMES_zu(id, size) LOOP(size_t, id, size)
#define TIMES_d(id, size) LOOP(int, id, size)
#define TIMES_ull(id, size) LOOP(uint64_t, id, size)


#define MIN(x, y) (((x) < (y) ? (x) : (y)))
#define MAX(x, y) (((x) > (y) ? (x) : (y)))

#endif //ISMDEEP_C_UTILS_MACRO_HEADER_H
