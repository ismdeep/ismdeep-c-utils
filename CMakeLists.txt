cmake_minimum_required(VERSION 2.8)

project(ismdeep-c-utils)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-W")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-W")

include_directories("include")

add_library(ismdeep-c-utils SHARED
        include/ismdeep-c-utils/argv.c
        include/ismdeep-c-utils/array.c
        include/ismdeep-c-utils/time.c
        include/ismdeep-c-utils/gf2_matrix.c
        include/ismdeep-c-utils/gf2_qc_encoder.c)


add_library(ismdeep-cpp-utils SHARED
        include/ismdeep-cpp-utils/ArgsParser.cpp)

add_executable(argv-utils-test tests/argv_utils_test.c)
target_link_libraries(argv-utils-test ismdeep-c-utils)

add_executable(threadpool-test tests/threadpool_test.c)
target_link_libraries(threadpool-test ismdeep-c-utils)

add_executable(simple-config-test tests/simple_config_test.c)

add_executable(gf2-matrix-test tests/gf2_matrix_test.c)
target_link_libraries(gf2-matrix-test ismdeep-c-utils)

add_executable(time_h_unix_time_to_date_test tests/time_h_unix_time_to_date_test.c)
target_link_libraries(time_h_unix_time_to_date_test ismdeep-c-utils)

add_executable(string-test tests/string_test.c)

add_executable(gf2-qc-encoder-test tests/gf2_qc_encoder_test.c)
target_link_libraries(gf2-qc-encoder-test ismdeep-c-utils)

add_executable(args-parser-test tests/args_parser_test.cpp)
target_link_libraries(args-parser-test
        ismdeep-c-utils
        ismdeep-cpp-utils)