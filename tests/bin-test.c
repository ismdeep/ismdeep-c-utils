//
// Created by L. Jiang <l.jiang.1024@gmail.com> on 2021/1/31.
//


#include <stdio.h>
#include <inttypes.h>

#include <ismdeep-c-utils/time.h>
#include <ismdeep-c-utils/bin.h>


int count_bit_naive(uint64_t val) {
    int cnt = 0;
    while (val) {
        cnt += (int) (val & 1UL);
        val >>= 1UL;
    }
    return cnt;
}

int main() {
    int n = 10000000;
    int passed = 0;
    while (n--) {
        uint64_t val = time_us();
        if (count_bit_naive(val) != count_bit(val)) {
            printf("ERROR: %"PRIu64"\n", val);
        } else {
            ++passed;
        }
    }

    printf("Passed: %d\n", passed);

    return 0;
}
