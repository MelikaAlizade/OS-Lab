#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *child(void *arg) {
    printf("Child thread PID: %d\n", getpid());
}

int main() {
    pthread_t thread;
    printf("Main PID: %d\n", getpid());
    pthread_create(&thread, NULL, child, NULL);
    pthread_join(thread, NULL);
    puts("Main: child thread finished.\n");
    return 0;
}
