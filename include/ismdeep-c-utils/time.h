//
// Created by L. Jiang <l.jiang.1024@gmail.com> on 2019/12/25.
//

#ifndef ISMDEEP_C_UTILS_TIME_UTILS_H
#define ISMDEEP_C_UTILS_TIME_UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>


#define SLEEP_S(x) usleep(x * 1000 * 1000)
#define SLEEP_MS(x) usleep(x * 1000)

void create_start_point(struct timeval *t) {
    gettimeofday(t, NULL);
}

uint64_t stop_watch_us(struct timeval t1) {
    struct timeval t2;
    gettimeofday(&t2, NULL);
    uint64_t timestamp1 = (uint64_t) t1.tv_sec * 1000000 + t1.tv_usec;
    uint64_t timestamp2 = (uint64_t) t2.tv_sec * 1000000 + t2.tv_usec;
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
    uint64_t timestamp = (uint64_t) t.tv_sec * 1000 + t.tv_usec / 1000;
    return timestamp;
}


uint64_t get_current_timestamp_us() {
    struct timeval t;
    gettimeofday(&t, NULL);
    uint64_t timestamp = (uint64_t) t.tv_sec * 1000000 + t.tv_usec;
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

uint64_t time_s() {
    struct timeval t;
    gettimeofday(&t, NULL);
    return t.tv_sec;
}

uint64_t time_ms() {
    struct timeval t;
    gettimeofday(&t, NULL);
    uint64_t timestamp = (uint64_t) t.tv_sec * 1000 + t.tv_usec / 1000;
    return timestamp;
}


uint64_t time_us() {
    struct timeval t;
    gettimeofday(&t, NULL);
    uint64_t timestamp = (uint64_t) t.tv_sec * 1000000 + t.tv_usec;
    return timestamp;
}

char *unix_time_to_date(int timestamp, char *format) {
    char *buf = (char *) malloc(sizeof(char) * 80);
    // Get current time
    time_t unix_time_val = timestamp;
    struct tm ts = *localtime(&unix_time_val);
    strftime(buf, sizeof(buf) * 80, format, &ts);
    return buf;
}

char *time_human_text(uint64_t interval_time_us) {
    char *str = (char *) malloc(sizeof(char) * 64);
    if (interval_time_us <= 1000) {
        sprintf(str, "%" PRIu64 " (us)", interval_time_us);
        return str;
    }

    uint64_t interval_time_ms = interval_time_us / 1000ULL;
    if (interval_time_ms <= 1000) {
        sprintf(str, "%" PRIu64 " (ms)", interval_time_ms);
        return str;
    }

    uint64_t interval_time_s;
    uint64_t interval_time_min;
    uint64_t interval_time_hour;
    uint64_t interval_time_day;

    interval_time_s = interval_time_ms / 1000ULL;
    interval_time_ms %= 1000ULL;

    interval_time_min = interval_time_s / 60ULL;
    interval_time_s %= 60ULL;

    interval_time_hour = interval_time_min / 60ULL;
    interval_time_min %= 60ULL;

    interval_time_day = interval_time_hour / 24ULL;
    interval_time_hour %= 24ULL;

    bool started = false;

    if (interval_time_day > 0) {
        started = true;
        char tmp[60];
        sprintf(tmp, "%" PRIu64 "d ", interval_time_day);
        strcat(str, tmp);
    }

    if (interval_time_hour > 0 || started) {
        started = true;
        char tmp[60];
        sprintf(tmp, "%02" PRIu64 ":", interval_time_hour);
        strcat(str, tmp);
    }

    if (interval_time_min > 0 || started) {
        started = true;
        char tmp[60];
        sprintf(tmp, "%02" PRIu64 ":", interval_time_min);
        strcat(str, tmp);
    }

    char tmp[60];
    sprintf(tmp, "%02" PRIu64 ".%03" PRIu64, interval_time_s, interval_time_ms);
    strcat(str, tmp);
    return str;
}


#endif //ISMDEEP_C_UTILS_TIME_UTILS_H
