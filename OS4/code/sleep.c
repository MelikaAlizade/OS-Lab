#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child: my PID: %d\n", getpid());
        printf("Child: parent PID before sleep: %d\n", getppid());
        sleep(5);
        printf("Child: parent PID after sleep: %d\n", getppid());
    } else {
        printf("Parent: my PID: %d\n", getpid());
        printf("Parent: parent process has finished!\n");
        exit(0);
    }
    return 0;
}
