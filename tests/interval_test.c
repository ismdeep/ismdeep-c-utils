//
// Created by L. Jiang <l.jiang.1024@gmail.com> on 2021/1/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <pthread.h>

#include <ismdeep-c-utils/interval.h>
#include <ismdeep-c-utils/macro_header.h>


void test_in_standalone() {
    struct Interval *interval = interval_create(1ULL, 100ULL, NULL);
    uint64_t l, r;

    while (interval_get(interval, &l, &r, 12)) {
        printf("%"PRIu64", %"PRIu64"\n", l, r);
    }
}

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
struct Interval *interval;

void thread_run() {
    uint64_t l, r;
    while (interval_get(interval, &l, &r, 10)) {
        printf("0x%"PRIx64" -> %"PRIu64", %"PRIu64"\n", (uint64_t) pthread_self(), l, r);
    }
}

void test_with_multi_thread() {
    interval = interval_create(1ULL, 100ULL, &mutex);
    int thread_size = 4;
    pthread_t *threads = (pthread_t *) malloc(sizeof(pthread_t) * thread_size);

    LOOP(int, thread_id, thread_size) {
        pthread_create(&threads[thread_id], NULL, (void *(*)(void *)) thread_run, NULL);
    }

    LOOP(int, thread_id, thread_size) {
        printf("thread_id join -> %d\n", thread_id);
        pthread_join(threads[thread_id], NULL);
    }

}

int main() {
    test_in_standalone();
    test_with_multi_thread();

    return EXIT_SUCCESS;
}