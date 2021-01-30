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

    uint64_t interval_time = end_time_us - monitor->start_time_us;
    if (interval_time <= 1000ULL) {
        printf("Time elapses: %"PRIu64" (us)\n", interval_time);
        return;
    }

    interval_time /= 1000ULL;
    if (interval_time <= 1000ULL) {
        printf("Time elapses: %"PRIu64" (ms)\n", interval_time);
        return;
    }

    double interval_time_f = interval_time;
    interval_time_f /= 1000.00;
    if (interval_time_f <= 60.00) {
        printf("Time elapses: %.2lf (s)\n", interval_time_f);
        return;
    }

    interval_time_f /= 60.00;
    if (interval_time_f <= 60) {
        printf("Time elapses: %.2lf (mins)\n", interval_time_f);
        return;
    }

    interval_time_f /= 60.0;
    if (interval_time_f <= 24) {
        printf("Time elapses: %.2lf (hours)\n", interval_time_f);
        return;
    }

    interval_time_f /= 24.0;
    printf("Time elapses: %.2lf (days)\n", interval_time_f);
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
