//
// Created by L. Jiang <l.jiang.1024@gmail.com> on 2020/12/9.
//


#include <stdio.h>
#include <stdlib.h>
#include <ismdeep-c-utils/simple_config.h>


void test_config_init() {
    struct ConfigBundle *config = config_init();

    config_put(config, "hello", "world");
    config_display(config);

    config_put(config, "hello", "there");
    config_display(config);

    printf("[%s]\n", config_get(config, "hello"));
    printf("[%s]\n", config_get(config, "OJ_SITE"));

    config_put(config, "hello", "10");
    printf("[%ld]\n", config_get_long(config, "hello"));


    config_put_long(config, "MYSQL_PORT", 3306);
    printf("%s\n", config_get(config, "MYSQL_PORT"));
    printf("%ld\n", config_get_long(config, "MYSQL_PORT"));
}

void test_config_parse() {
    struct ConfigBundle *config = config_init();
    config_parse(config, "hello\nhello = world\nMYSQL_HOST=127.0.0.1\nMYSQL_PORT=3306\n\n");
    printf("%s\n", config_get(config, "MYSQL_HOST"));
    config_display(config);
}

void test_config_parse_file() {
    FILE *fp = fopen("in.txt", "r");
    struct ConfigBundle *config = config_init();
    config_parse_file(config, fp);
    config_display(config);
}

void test_config_dump_file() {
    struct ConfigBundle *config = config_init();
    config_put(config, "MYSQL_HOST", "127.0.0.1");
    config_put_long(config, "MYSQL_PORT", 3306);
    config_put(config, "MYSQL_DBNAME", "justoj");
    config_put(config, "MYSQL_USERNAME", "justoj");
    config_put(config, "MYSQL_PASSWORD", "123456");
    config_display(config);
    config_display(config);
    config_display(config);
    config_display(config);

    FILE *fp = fopen("in.txt", "w");
    config_dump_file(config, fp);
    fclose(fp);
}


int main() {

//    test_config_parse();

//    test_config_parse_file();

    test_config_dump_file();

    return EXIT_SUCCESS;
}