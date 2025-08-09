#include <stdio.h>
#include <unistd.h>

int main(void) {
    alarm(5);
    printf("Looping forever...\n");
    while (1);
       printf("This line should never be executed.\n");
    return 0;
}
