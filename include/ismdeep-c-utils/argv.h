//
// Created by L. Jiang <l.jiang.1024@gmail.com> on 2020/1/5.
//

#ifndef ISMDEEP_C_UTILS_ARGV_UTILS_H
#define ISMDEEP_C_UTILS_ARGV_UTILS_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

const char *get_argv(int argc, const char *argv[], const char *search_key) {
    for (int i = 0; i < argc - 1; ++i) {
        if (strcmp(search_key, argv[i]) == 0) {
            return argv[i + 1];
        }
    }
    return "";
}

int get_argv_int(int argc, const char *argv[], const char *search_key) {
    const char *tmp = get_argv(argc, argv, search_key);
    int ans = atoi(tmp);
    return ans;
}

uint64_t get_argv_uint64_t(int argc, const char *argv[], const char *search_key) {
    const char *tmp = get_argv(argc, argv, search_key);
    return strtoull(tmp, NULL, 10);
}



bool argv_switch_exist(int argc, const char *argv[], const char *search_key) {
    for (int i = 0; i < argc; ++i) {
        if (strcmp(argv[i], search_key) == 0) {
            return true;
        }
    }
    return false;
}

bool argv_switch_not_exist(int argc, const char *argv[], const char *search_key) {
    return !argv_switch_exist(argc, argv, search_key);
}

#endif //ISMDEEP_C_UTILS_ARGV_UTILS_H
