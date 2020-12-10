//
// Created by Del Cooper on 2020/12/10.
//

#include <stdio.h>
#include <stdlib.h>
#include <ismdeep-c-utils/time.h>

int main() {

    printf("Date: [%s]\n", unix_time_to_date(1607522627, "%a %Y-%m-%d %H:%M:%S"));

    return EXIT_SUCCESS;
}