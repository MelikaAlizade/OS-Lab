#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

typedef struct thdata {
    int thread_no;
    char message[100];
} stdata;

void* child(void* arg) {
    stdata* data = (stdata*) arg;
    printf("Thread number: %d\n", data->thread_no);
    printf("Message: %s\n", data->message);
    return NULL;
}

int main() {
    pthread_t th1, th2;
    stdata data1, data2;
    data1.thread_no = 1;
    strcpy(data1.message, "Message from thread 1!");
    pthread_create(&th1, NULL, child, (void*)&data1);
    pthread_join(th1, NULL);

    data2.thread_no = 2;
    strcpy(data2.message, "Message from thread 2!");
    pthread_create(&th2, NULL, child, (void*)&data2);
    pthread_join(th2, NULL);

    return 0;
}
