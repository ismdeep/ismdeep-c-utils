//
// Created by L. Jiang on 2021/1/30.
//

#ifndef ISMDEEP_C_UTILS_MONITOR_UTIL_H
#define ISMDEEP_C_UTILS_MONITOR_UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <inttypes.h>

#include <pthread.h>

#include "time.h"


typedef void (*monitor_func_t) ();

struct Monitor {
    uint64_t start_time_us;
    pthread_t *thread;
    monitor_func_t func;
    bool is_running;
    useconds_t sleep_time_ms;
};

void monitor_pthread_runner(struct Monitor *monitor) {
    while (true) {
        monitor->func();
        if (!monitor->is_running) {
            break;
        }
        SLEEP_MS(monitor->sleep_time_ms);
    }
    printf("\n");

    uint64_t end_time_us = time_us();

    uint64_t interval_time_us = end_time_us - monitor->start_time_us;

    char *str = time_human_text(interval_time_us);
    printf("Time elapses: %s\n", str);
    free(str);
}

struct Monitor *monitor_create(monitor_func_t func, useconds_t sleep_time_ms) {
    struct Monitor *monitor = (struct Monitor *) malloc(sizeof(struct Monitor) * 1);
    monitor->func = func;
    monitor->is_running = true;
    monitor->sleep_time_ms = sleep_time_ms;
    return monitor;
}

void monitor_start(struct Monitor *monitor) {
    monitor->thread = (pthread_t *) malloc(sizeof(pthread_t) * 1);
    monitor->start_time_us = time_us();
    pthread_create(monitor->thread, NULL, (void *(*)(void *)) monitor_pthread_runner, monitor);
}

void monitor_join(struct Monitor *monitor) {
    pthread_join(*monitor->thread, NULL);
}


#endif //ISMDEEP_C_UTILS_MONITOR_UTIL_H
