//
// Created by L. Jiang <l.jiang.1024@gmail.com> on 2019/12/25.
//

#ifndef ISMDEEP_C_UTILS_STRING_UTILS_H
#define ISMDEEP_C_UTILS_STRING_UTILS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "macro_header.h"

struct IString {
    char *data;
};


char *int_to_string(int val) {
    char *str = (char *) malloc(256 * sizeof(char));
    sprintf(str, "%d", val);
    return str;
}

int string_to_int(const char *str) {
    int ans = (int) strtol(str, NULL, 10);
    return ans;
}

/* ' ', '\n', '\r', '\t' */
bool is_space_char(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}

char *strip(const char *str) {
    size_t left = 0;
    size_t right = strlen(str) - 1;

    while (left <= right && is_space_char(str[left])) {
        ++left;
    }

    while (right >= left && is_space_char(str[right])) {
        --right;
    }

    printf("left: %zu    right:%zu\n", left, right);

    if (right < left) {
        return "";
    }

    char *ans = (char *) malloc(sizeof(char) * (right - left + 2));
    memset(ans, 0, sizeof(char) * (right - left + 2));

    for (size_t i = 0; i <= right - left; ++i) {
        ans[i] = str[left + i];
    }

    return ans;
}

char **split(const char *str, char sep) {
    size_t cnt = 0;
    LOOP(size_t, i, strlen(str)) {
        if (str[i] == sep) {
            ++cnt;
        }
    }
    ++cnt;

    char **items = (char **) malloc(sizeof(char *) * (cnt + 1));
    LOOP(size_t, i, cnt + 1) {
        items[i] = NULL;
    }

    size_t left = 0;
    size_t index = 0;
    LOOP(size_t, cursor, strlen(str)) {
        if (str[cursor] == sep) {
            char *s = (char *) malloc(sizeof(cursor - left + 1));
            memset(s, 0, sizeof(cursor - left + 1));
            LOOP(size_t, i, cursor - left) {
                s[i] = str[left + i];
            }
            left = cursor + 1;
            items[index++] = s;
        }
    }

    char *s = (char *) malloc(sizeof(strlen(str) - left + 1));
    memset(s, 0, sizeof(strlen(str) - left + 1));
    LOOP(size_t, i, strlen(str) - left) {
        s[i] = str[left + i];
    }
    items[index] = s;

    return items;
}


struct IString *get_lines(const char *_content_) {
    char *content = (char *) malloc(sizeof(char) * (strlen(_content_) + 5));
    strcpy(content, _content_);
    content[strlen(content)] = '\0';
    content[strlen(content) + 1] = '\0';
    content[strlen(content)] = '\n';

    size_t line_cnt = 0;
    for (size_t i = 0; i < strlen(content); i++) {
        ++line_cnt;
    }

    struct IString *lines = (struct IString *) malloc(sizeof(struct IString) * (line_cnt + 1));
    for (size_t i = 0; i < line_cnt + 1; i++) {
        lines[i].data = NULL;
    }
    size_t lines_size = 0;

    char *cursor = content;

    size_t content_len = strlen(content);

    for (size_t i = 0; i < content_len; i++) {
        if (content[i] == '\n') {
            content[i] = '\0';
            lines[lines_size].data = (char *) malloc(sizeof(char) * (content + i - cursor + 3));
            strcpy(lines[lines_size].data, cursor);
            lines_size++;
            cursor = content + i + 1;
        }
    }

    free(content);

    return lines;
}




#endif //ISMDEEP_C_UTILS_STRING_UTILS_H
