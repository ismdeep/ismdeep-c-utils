//
// Created by L. Jiang <l.jiang.1024@gmail.com> on 2019/12/25.
//

#ifndef ISMDEEP_C_UTILS_STRING_UTILS_H
#define ISMDEEP_C_UTILS_STRING_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

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

char *strip(const char *_line_args_) {
    if (strcmp(_line_args_, "") == 0) {
        return "";
    }

    char *line = (char *) malloc(sizeof(char) + (strlen(_line_args_) + 2));
    strcpy(line, _line_args_);

    size_t left = 0;
    size_t right = strlen(line) - 1;
    while (left < strlen(line) && (line[left] == ' ' || line[left] == '\t' || line[left] == '\n')) left++;
    while (right >= 0 && ((line[right] == ' ' || line[right] == '\t' || line[right] == '\n'))) right--;

    if (right < left) {
        return "";
    }

    char *ans = (char *) malloc(sizeof(char) * (right - left + 5));
    line[right + 1] = '\0';
    strcpy(ans, line + left);

    return ans;
}

struct IString *get_lines(const char *_content_) {
    char *content = (char *) malloc(sizeof(char) * (strlen(_content_) + 5));
    strcpy(content, _content_);
    content[strlen(content)] = '\0';
    content[strlen(content)+1] = '\0';
    content[strlen(content)] = '\n';

    size_t  line_cnt = 0;
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
