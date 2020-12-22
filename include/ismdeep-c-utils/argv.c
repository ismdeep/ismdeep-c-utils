//
// Created by L. Jiang on 2020/12/22.
//

#include "argv.h"


#include <stdbool.h>
#include <string.h>

const char *get_argv(int argc, const char *argv[], const char *search_key) {
    for (int i = 0; i < argc - 1; ++i) {
        if (strcmp(search_key, argv[i]) == 0) {
            return argv[i + 1];
        }
    }
    return "";
}


bool argv_exist_switch(int argc, const char *argv[], const char *search_key) {
    for (int i = 0; i < argc; ++i) {
        if (strcmp(argv[i], search_key) == 0) {
            return true;
        }
    }
    return false;
}