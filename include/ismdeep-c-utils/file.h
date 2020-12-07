//
// Created by L. Jiang <l.jiang.1024@gmail.com> on 2019/12/25.
//

#ifndef ISMDEEP_C_UTILS_FILE_UTILS_H
#define ISMDEEP_C_UTILS_FILE_UTILS_H

#include <stdint.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

size_t get_file_size(const char *file_path) {
    FILE *fp = fopen(file_path, "rb");
    fseek(fp, 0, SEEK_END);
    uint64_t file_size = (uint64_t) ftell(fp);
    fseek(fp, 0, SEEK_SET);
    fclose(fp);
    return file_size;
}


/**
 * Read data
 *
 * @param data
 * @param offset
 * @param size
 * @param file
 */
void read_data(void *data, size_t offset, size_t size, FILE *file) {
    fseek(file, offset, SEEK_SET);
    fread(data, sizeof(uint8_t), size, file);
}

/**
 * Read data with mutex
 *
 * @param data
 * @param offset
 * @param block_items_size
 * @param file
 * @param mutex_pointer
 */
void read_data_with_mutex(void *data, size_t offset, size_t size, FILE *file, pthread_mutex_t *mutex_pointer) {
    pthread_mutex_lock(mutex_pointer);
    read_data(data, offset, size, file);
    pthread_mutex_unlock(mutex_pointer);
}

/**
 * Write data
 *
 * @param data
 * @param offset
 * @param size
 * @param file
 */
void write_data(void *data, size_t offset, size_t size, FILE *file) {
    fseek(file, offset, SEEK_SET);
    fwrite(data, sizeof(uint8_t), size, file);
}

/**
 * Write data with mutex
 *
 * @param data
 * @param offset
 * @param size
 * @param file
 * @param mutex_pointer
 */
void write_data_with_mutex(void *data, size_t offset, size_t size, FILE *file, pthread_mutex_t *mutex_pointer) {
    pthread_mutex_lock(mutex_pointer);
    write_data(data, offset, size, file);
    pthread_mutex_unlock(mutex_pointer);
}

#endif //ISMDEEP_C_UTILS_FILE_UTILS_H
