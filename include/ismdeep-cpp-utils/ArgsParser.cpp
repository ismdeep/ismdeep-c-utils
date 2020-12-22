//
// Created by L. Jiang <l.jiang.1024@gmail.com> on 2020/12/22.
//

#include "ArgsParser.h"


ArgsParser::ArgsParser(int _argc_, const char **_argv_) {
    set_data(_argc_, _argv_);
}

void ArgsParser::set_data(int _argc_, const char **_argv_) {
    this->argc = _argc_;
    this->argv = _argv_;
}

int ArgsParser::get_int(const char *search_key) {
    const char *tmp = get_argv(this->argc, this->argv, search_key);
    int val = (int) strtol(tmp, nullptr, 10);
    return val;
}

std::string ArgsParser::get_string(const char *search_key) {
    const char *tmp = get_argv(this->argc, this->argv, search_key);
    std::string str(tmp);
    return str;
}

bool ArgsParser::has(const char *search_key) {
    return argv_exist_switch(this->argc, this->argv, search_key);
}
