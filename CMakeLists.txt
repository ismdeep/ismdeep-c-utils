cmake_minimum_required(VERSION 2.8)

project(ismdeep-c-utils)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-W")
set(CMAKE_C_FLAGS "-lpthread")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-W")
set(CMAKE_CXX_FLAGS "-std=c++0x")
set(CMAKE_CXX_FLAGS "-lpthread")

include_directories("include")

add_executable(argv-utils-test tests/argv_utils_test.c)

add_executable(threadpool-test tests/threadpool_test.c)

add_executable(simple-config-test tests/simple_config_test.c)

add_executable(gf2-matrix-test tests/gf2_matrix_test.c)

add_executable(time_h_unix_time_to_date_test tests/time_h_unix_time_to_date_test.c)

add_executable(string-test tests/string_test.c)

add_executable(gf2-qc-encoder-test tests/gf2_qc_encoder_test.c)

add_executable(args-parser-test tests/args_parser_test.cpp)

add_executable(interval-test tests/interval_test.c)
