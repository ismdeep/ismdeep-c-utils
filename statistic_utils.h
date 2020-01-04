//
// Created by ismdeep on 2020/1/4.
//

#ifndef ISMDEEP_C_UTILS_STATISTIC_UTILS_H
#define ISMDEEP_C_UTILS_STATISTIC_UTILS_H

#include <macro_header.h>

double statistic_avg(double *data, size_t size) {
    double sum = 0.00;
    TIMES(data_id, size) {
        sum += data[data_id];
    }
    return sum;
}

double statistic_var(double *data, size_t size) {
    double avg = statistic_avg(data, size);
    double sum = 0.00;
    TIMES(data_id, size) {
        sum += (avg - data[data_id]) * (avg - data[data_id]);
    }
    return sum / size;
}

#endif //ISMDEEP_C_UTILS_STATISTIC_UTILS_H
