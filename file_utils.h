//
// Created by ismdeep on 2019/12/25.
//

#ifndef ISMDEEP_C_UTILS_FILE_UTILS_H
#define ISMDEEP_C_UTILS_FILE_UTILS_H

#include <stdint.h>

uint64_t get_file_size(const char * file_path) {
    FILE * fp = fopen(file_path, "rb");
    fseek(fp, 0, SEEK_END);
    uint64_t file_size = (uint64_t) ftell(fp);
    fseek(fp, 0, SEEK_SET);
    fclose(fp);
    return file_size;
}

#endif //ISMDEEP_C_UTILS_FILE_UTILS_H
