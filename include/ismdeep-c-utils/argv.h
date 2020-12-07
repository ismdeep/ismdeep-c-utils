//
// Created by L. Jiang <l.jiang.1024@gmail.com> on 2020/1/5.
//

#ifndef ISMDEEP_C_UTILS_ARGV_UTILS_H
#define ISMDEEP_C_UTILS_ARGV_UTILS_H

#include <stdbool.h>
#include <string.h>

char * get_argv(int argc, char * argv[], const char * search_key) {
    for (int i = 0; i < argc - 1; ++i) {
        if (strcmp(search_key, argv[i]) == 0) {
            return argv[i+1];
        }
    }
    return "";
}


bool argv_exist_switch(int argc, char* argv[], const char * search_key) {
    for (int i = 0; i < argc; ++i) {
        if (strcmp(argv[i], search_key) == 0) {
            return true;
        }
    }
    return false;
}

#endif //ISMDEEP_C_UTILS_ARGV_UTILS_H
