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


#define SLEEP_S(x) usleep(x * 1000 * 1000)
#define SLEEP_MS(x) usleep(x * 1000)

void create_start_point(struct timeval *t);

uint64_t stop_watch_us(struct timeval t1);

uint64_t stop_watch_ms(struct timeval t1);

uint64_t get_current_timestamp_s();

uint64_t get_current_timestamp_ms();

uint64_t get_current_timestamp_us();

char *current_time();

char *current_time_id();

uint64_t time_s();

uint64_t time_ms();

uint64_t time_us();

char *unix_time_to_date(int timestamp, char *format);

#endif //ISMDEEP_C_UTILS_TIME_UTILS_H
