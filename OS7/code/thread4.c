#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int n;

void *child(void *arg) {
    long s = 0;
    if (n<2) {
        printf("n is less than 2!\n");
	return NULL;
    }
    for (int i = 2; i <= n; i++) {
        s += i;
    }
    printf("sum = %ld\n", s);
    return NULL;
}

int main(void) {
    printf("Enter a number: ");
    scanf("%d", &n);
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_t th;
    pthread_create(&th, &attr, child,NULL);
    pthread_attr_destroy(&attr);
    pthread_join(th, NULL);
    return 0;
}
