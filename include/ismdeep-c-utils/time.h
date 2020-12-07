//
// Created by L. Jiang <l.jiang.1024@gmail.com> on 2019/12/25.
//

#ifndef ISMDEEP_C_UTILS_TIME_UTILS_H
#define ISMDEEP_C_UTILS_TIME_UTILS_H

#include <time.h>
#include <sys/time.h>
#include <stdint.h>

void create_start_point(struct timeval * t) {
    gettimeofday(t, NULL);
}

uint64_t stop_watch_us(struct timeval t1) {
    struct timeval t2;
    gettimeofday(&t2, NULL);
    uint64_t timestamp1 = (uint64_t)t1.tv_sec * 1000000 + t1.tv_usec;
    uint64_t timestamp2 = (uint64_t)t2.tv_sec * 1000000 + t2.tv_usec;
    return timestamp2 - timestamp1;
}

uint64_t stop_watch_ms(struct timeval t1) {
    return stop_watch_us(t1) / 1000;
}

uint64_t get_current_timestamp_s() {
    struct timeval t;
    gettimeofday(&t, NULL);
    return t.tv_sec;
}

uint64_t get_current_timestamp_ms() {
    struct timeval t;
    gettimeofday(&t, NULL);
    uint64_t timestamp = (uint64_t)t.tv_sec * 1000 + t.tv_usec / 1000;
    return timestamp;
}


uint64_t get_current_timestamp_us() {
    struct timeval t;
    gettimeofday(&t, NULL);
    uint64_t timestamp = (uint64_t)t.tv_sec * 1000000 + t.tv_usec;
    return timestamp;
}


char *current_time() {
    time_t now;
    struct tm *timenow;
    time(&now);
    timenow = localtime(&now);
    char *str = (char *) malloc(1024 * sizeof(char));
    sprintf(str, "%04d-%02d-%02d %02d:%02d:%02d",
            timenow->tm_year + 1900, timenow->tm_mon + 1, timenow->tm_mday,
            timenow->tm_hour, timenow->tm_min, timenow->tm_sec
    );
    return str;
}

char *current_time_id() {
    time_t now;
    struct tm *time_now;
    time(&now);
    time_now = localtime(&now);
    char *str = (char *) malloc(1024 * sizeof(char));
    sprintf(str, "%04d%02d%02d%02d%02d%02d",
            time_now->tm_year + 1900, time_now->tm_mon + 1, time_now->tm_mday,
            time_now->tm_hour, time_now->tm_min, time_now->tm_sec
    );
    return str;
}

#endif //ISMDEEP_C_UTILS_TIME_UTILS_H
