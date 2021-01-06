//
// Created by L. Jiang <l.jiang.1024@gmail.com> on 2020/12/11.
//

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include <ismdeep-c-utils/string.h>

int main() {

    printf("%d\n", string_to_int("1092"));

    printf("%s\n", int_to_string(1092));

    uint64_t v = strtoull("18236", NULL, 10);

    printf("%"PRIu64, v);

    printf("[%s]\n", strip("  "));

    printf("[%s]\n", strip("a  "));

    printf("[%s]\n", strip("  a"));

    printf("[%s]\n", strip(" a "));


    /* split */
    char **items = split("hello,world,,", ',');
    for (size_t i = 0; items[i] != NULL; i++) {
        printf("[%s]\n", items[i]);
    }

    return EXIT_SUCCESS;
}