cmake_minimum_required(VERSION 2.8)

project(ismdeep-c-utils)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-W")
include_directories("include")

add_executable(argv-utils-test tests/argv_utils_test.c)