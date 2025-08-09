#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

volatile sig_atomic_t flag = 0;

void flag_handler(int signo) {
    flag = 1;
}

int main() {

    signal(SIGALRM, flag_handler);
    alarm(5);
    printf("Looping until SIGALRM...\n");
    while (!flag) {
        pause();
    }
    printf("This line now has executed.\n");
    return 0;
}
