#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int ret = fork();
    int x = 5;
    if (ret == 0) {
        x ++;
        printf("Child x: %d\n", x);
    } else {
        x--;
        wait(NULL);
        printf("Parent x: %d\n", x);
    }
    return 0;
}