#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

volatile sig_atomic_t counter = 0;

void counter_handler(int signo) {
    counter++;
}

int main() {
    signal(SIGINT, counter_handler);
    printf("Program running...\n");
    while (counter<2) {
        pause();
	if (counter==1){
	   printf(" - You press Cntrl+C once!\n");
        }
    }
    printf(" - You press Cntrl+C for second time!\n");
    return 0;
}
