//
// Created by L. Jiang on 2020/12/21.
//

#ifndef ISMDEEP_C_UTILS_ARGSPARSER_H
#define ISMDEEP_C_UTILS_ARGSPARSER_H

#include <cstdlib>
#include <string>

#include "../ismdeep-c-utils/argv.h"
#include "../ismdeep-c-utils/argv.c"

class ArgsParser {
private:
    int argc{};
    const char **argv{};

public:
    ArgsParser(int _argc_, const char **_argv_);

    void set_data(int _argc_, const char **_argv_);

    int get_int(const char *search_key);

    std::string get_string(const char *search_key);

    bool has(const char *search_key);
};


#endif //ISMDEEP_C_UTILS_ARGSPARSER_H
