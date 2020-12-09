//
// Created by L. Jiang <l.jiang.1024@gmail.com> on 2020/12/7.
//

#include <stdio.h>
#include <stdlib.h>
#include <ismdeep-c-utils/threadpool.h>
#include <ismdeep-c-utils/time.h>

uint64_t fib(uint64_t n) {
    if (n <= 1) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}


void *work(void *arg) {
    char *p = (char *) arg;
    uint64_t ans = fib(40);
    printf("%p %s threadpool callback function. fib(40) = %llu\n", pthread_self(), p, ans);
    return NULL;
}


int main() {

    uint64_t start_time = time_ms();

    struct ThreadPool *pool = threadpool_init(10, 20);
    threadpool_add_job(pool, work, "1");
    threadpool_add_job(pool, work, "2");
    threadpool_add_job(pool, work, "3");
    threadpool_add_job(pool, work, "4");
    threadpool_add_job(pool, work, "5");
    threadpool_add_job(pool, work, "6");
    threadpool_add_job(pool, work, "7");
    threadpool_add_job(pool, work, "8");
    threadpool_add_job(pool, work, "9");
    threadpool_add_job(pool, work, "10");
    threadpool_add_job(pool, work, "11");
    threadpool_add_job(pool, work, "12");
    threadpool_add_job(pool, work, "13");
    threadpool_add_job(pool, work, "14");
    threadpool_add_job(pool, work, "15");
    threadpool_add_job(pool, work, "16");
    threadpool_add_job(pool, work, "17");
    threadpool_add_job(pool, work, "18");
    threadpool_add_job(pool, work, "19");
    threadpool_add_job(pool, work, "20");
    threadpool_add_job(pool, work, "21");
    threadpool_add_job(pool, work, "22");
    threadpool_add_job(pool, work, "23");
    threadpool_add_job(pool, work, "24");
    threadpool_add_job(pool, work, "25");
    threadpool_add_job(pool, work, "26");
    threadpool_add_job(pool, work, "27");
    threadpool_add_job(pool, work, "28");
    threadpool_add_job(pool, work, "29");
    threadpool_add_job(pool, work, "30");
    threadpool_add_job(pool, work, "31");
    threadpool_add_job(pool, work, "32");
    threadpool_add_job(pool, work, "33");
    threadpool_add_job(pool, work, "34");
    threadpool_add_job(pool, work, "35");
    threadpool_add_job(pool, work, "36");
    threadpool_add_job(pool, work, "37");
    threadpool_add_job(pool, work, "38");
    threadpool_add_job(pool, work, "39");
    threadpool_add_job(pool, work, "40");

    threadpool_destroy(pool);

    uint64_t end_time = time_ms();

    printf("DONE. Time elapse: %llu (ms)\n", end_time - start_time);

    return EXIT_SUCCESS;
}