#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int thread_num = 6;

void *hello_world(void *arg) {
    int id = *(int *)arg;
    printf("Hello World thread %d\n", id);
    free(arg);
    pthread_exit(0);
}

int main(void) {
    pthread_t threads[thread_num];
    for (int i = 0; i < thread_num; i++) {
         int *id = malloc(sizeof(int));
         *id = i + 1;
         pthread_create(&threads[i], NULL, hello_world, id);
    }
    pthread_exit(NULL);
    return 0;
}
