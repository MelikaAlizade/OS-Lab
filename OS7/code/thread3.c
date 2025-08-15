#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int oslab = 0;

void *child(void *arg) {
    printf("child (before): oslab= %d, addreass= %p\n", oslab, &oslab);
    oslab += 5;
    printf("child (after): oslab= %d, addreass= %p\n", oslab, &oslab);
}

int main() {
    pthread_t thread;
    printf("main (before): oslab= %d, addreass= %p\n", oslab, &oslab);
    oslab -= 2;
    printf("main (after): oslab= %d, addreass= %p\n", oslab, &oslab);
    pthread_create(&thread, NULL, child, NULL);
    pthread_join(thread, NULL);
    printf("OSlab after join: oslab= %d, addreass= %p\n", oslab, &oslab);
    return 0;
}
