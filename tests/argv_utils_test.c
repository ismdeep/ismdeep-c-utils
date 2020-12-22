//
// Created by L. Jiang <l.jiang.1024@gmail.com> on 2020/12/7.
//

#include <stdio.h>
#include <stdlib.h>
#include <ismdeep-c-utils/argv.h>

int main(int argc, const char *argv[]) {
    if (argv_exist_switch(argc, argv, "--help")) {
        printf("--help FOUND.\n");
    } else {
        printf("--help NOT FOUND.\n");
    }
    return EXIT_SUCCESS;
}