#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int ret1 = fork();
    if (ret1 == 0) {
        printf("child\n");
    } else {
        wait(NULL);
        printf("parent\n");
    }
    printf("after first fork.\n");
    int ret2 = fork();
    if (ret2 == 0) {
        printf("child\n");
    } else {
        wait(NULL);
        printf("parent\n");
    }
    printf("after second fork.\n");
    int ret3 = fork();
    if (ret3 == 0) {
        printf("child\n");
    } else {
        wait(NULL);
        printf("parent\n");
    }
    printf("after third fork.\n");
    return 0;
}