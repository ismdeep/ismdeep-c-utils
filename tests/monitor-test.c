//
// Created by L. Jiang on 2021/1/30.
//

#include <stdio.h>
#include <stdlib.h>
#include <ismdeep-c-utils/monitor-util.h>
#include <ismdeep-c-utils/time.h>

uint64_t start_time_us;
int val;

void show_msg() {
    printf("\r%s -> %d", time_human_text(time_us() - start_time_us), val);
    fflush(stdout);
}

uint64_t fib(int n) {
    return n <= 1 ? n : fib(n - 1) + fib(n - 2);
}

int main() {
    struct Monitor *monitor = monitor_create(show_msg, 200);
    start_time_us = time_us();
    monitor_start(monitor);

    for (int i = 0; i < 44; i++) {
        val = i;
        uint64_t tmp = fib(i);
    }

    monitor->is_running = false;
    monitor_join(monitor);

    return EXIT_SUCCESS;
}