//
// Created by L. Jiang <l.jiang.1024@gmail.com> on 2020/12/11.
//

#include <stdio.h>
#include <stdlib.h>

#include <ismdeep-c-utils/string.h>

int main() {

    printf("%d\n", string_to_int("1092"));

    printf("%s\n", int_to_string(1092));

    return EXIT_SUCCESS;
}