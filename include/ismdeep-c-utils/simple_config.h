//
// Created by L. Jiang <l.jiang.1024@gmail.com> on 2020/12/9.
//

/**
 *
 *
 * KEY = VALUE     Form configuration
 *
 *
 *
 */

#ifndef ISMDEEP_C_UTILS_SIMPLE_CONFIG_H
#define ISMDEEP_C_UTILS_SIMPLE_CONFIG_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include <ismdeep-c-utils/string.h>

#define CONFIG_SIZE_MAX 4096


struct ConfigBundle {
    size_t size;
    struct IString *key;
    struct IString *val;
};

struct ConfigBundle *config_init() {
    struct ConfigBundle *config_bundle = (struct ConfigBundle *) malloc(sizeof(struct ConfigBundle) * 1);
    config_bundle->size = 0;
    config_bundle->key = (struct IString *) malloc(sizeof(struct IString) * CONFIG_SIZE_MAX);
    config_bundle->val = (struct IString *) malloc(sizeof(struct IString) * CONFIG_SIZE_MAX);
    return config_bundle;
}

void config_put(struct ConfigBundle *config, const char *key, const char *val) {
    for (size_t i = 0; i < config->size; i++) {
        if (strcmp(key, config->key[i].data) == 0) {
            free(config->val[i].data);
            config->val[i].data = (char *) malloc(sizeof(char) * (strlen(val) + 2));
            strcpy(config->val[i].data, val);
            return;
        }
    }

    config->key[config->size].data = (char *) malloc(sizeof(char) * (strlen(key) + 2));
    config->val[config->size].data = (char *) malloc(sizeof(char) * (strlen(val) + 2));
    strcpy(config->key[config->size].data, key);
    strcpy(config->val[config->size].data, val);

    config->size++;
}

void config_put_bool(struct ConfigBundle *config, const char *key, bool bool_val) {
    config_put(config, key, bool_val ? "true" : "false");
}

void config_put_long(struct ConfigBundle *config, const char *key, long long_val) {
    char *tmp = (char *) malloc(sizeof(char) * 50);
    sprintf(tmp, "%ld", long_val);
    config_put(config, key, tmp);
}

char *config_get(const struct ConfigBundle *config, const char *key) {
    for (size_t i = 0; i < config->size; i++) {
        if (strcmp(key, config->key[i].data) == 0) {
            char *tmp = (char *) malloc(sizeof(char) * (strlen(config->val[i].data) + 2));
            strcpy(tmp, config->val[i].data);
            return tmp;
        }
    }

    return "";
}

bool config_get_bool(const struct ConfigBundle *config, const char *key) {
    char *tmp = config_get(config, key);
    char *trues[] = {"true", "True", "TRUE", "yes", "YES", "T", NULL};
    for (size_t i = 0; trues[i] != NULL; i++) {
        if (strcmp(tmp, trues[i]) == 0) {
            return true;
        }
    }

    return false;
}

long config_get_long(const struct ConfigBundle *config, const char *key) {
    char *tmp = config_get(config, key);
    if (strcmp(tmp, "") == 0) {
        return 0;
    }

    long ans;
    ans = strtol(tmp, NULL, 10);
    return ans;
}


char *config_dump(const struct ConfigBundle *config) {
    char *content = (char *) malloc(sizeof(char) * 65535);
    memset(content, 0, sizeof(char) * 65535);
    size_t size = config->size;
    for (size_t i = 0; i < size; i++) {
        char *tmp = (char *) malloc(sizeof(char) * 65535);
        memset(tmp, 0, sizeof(char) * 65535);
        sprintf(tmp, "%s = %s\n", config->key[i].data, config->val[i].data);
        strcat(content, tmp);
        free(tmp);
        tmp = NULL;
    }
    return content;
}

void config_dump_file(const struct ConfigBundle *config, FILE *fp) {
    char *content = config_dump(config);
    fprintf(fp, "%s\n", content);
    free(content);
    content = NULL;
}

void config_display(const struct ConfigBundle *config) {
    char *content = config_dump(config);
    printf("%s\n", content);
    free(content);
    content = NULL;
}



void config_parse_lines(struct ConfigBundle *config, const struct IString *lines) {
    for (size_t i = 0; lines[i].data != NULL; i++) {
        char *line = strip(lines[i].data);

        if (strcmp(line, "") == 0) {
            continue;
        }

        char *index = strstr(line, "=");
        if (index == NULL) {
            fprintf(stderr, "ERROR: [%s]\n", line);
            exit(0);
        }
        *index = '\0';
        index++;

        char *key = (char *) malloc(sizeof(char) * (strlen(line) + 1));
        char *val = (char *) malloc(sizeof(char) * (strlen(line) + 1));

        strcpy(key, line);
        strcpy(val, index);

        key = strip(key);
        val = strip(val);

        config_put(config, key, val);
    }
}

void config_parse(struct ConfigBundle *config, const char *content) {
    struct IString *lines = get_lines(content);
    config_parse_lines(config, lines);
}

void config_parse_file(struct ConfigBundle *config, FILE *fp) {
    if (fp == NULL) {
        return;
    }

    char *content = (char *) malloc(sizeof(char) * 65535);
    char *tmp = (char *) malloc(sizeof(char) * 65535);
    while (fgets(tmp, 65535, fp) != NULL) {
        strcat(content, tmp);
    }

    config_parse(config, content);
    free(content);
    content = NULL;
}

#endif //ISMDEEP_C_UTILS_SIMPLE_CONFIG_H
