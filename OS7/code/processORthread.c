#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int global_var; 
void *child(void *arg) {
    int local_var;
    printf("Thread %ld, pid %d, addresses: &global: %p, &local: %p \n",
           pthread_self(), getpid(), &global_var, &local_var);
    global_var++;
    printf("Thread %ld, pid %d, incremented global var=%d\n",
           pthread_self(), getpid(), global_var);
    pthread_exit(0);
}

int main() {
    pthread_t th1, th2;
    global_var = 10;
    printf("Main: global_var=%d\n", global_var);
    pthread_create(&th1, NULL, child, NULL);
    pthread_create(&th2, NULL, child, NULL);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    printf("Main after threads: global_var=%d\n", global_var);
    return 0;
}
