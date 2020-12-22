//
// Created by L. Jiang <l.jiang.1024@gmail.com> on 2020/1/5.
//

#ifndef ISMDEEP_C_UTILS_ARGV_UTILS_H
#define ISMDEEP_C_UTILS_ARGV_UTILS_H

#include <stdbool.h>
#include <string.h>

const char *get_argv(int argc, const char *argv[], const char *search_key);
bool argv_exist_switch(int argc, const char *argv[], const char *search_key);

#endif //ISMDEEP_C_UTILS_ARGV_UTILS_H
