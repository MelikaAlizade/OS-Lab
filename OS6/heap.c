#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    void *initial_brk = sbrk(0);
    printf("Initial end of heap address: %p\n", initial_brk);

    void *p1 = malloc(100);
    void *after_malloc = sbrk(0);
    printf("After malloc(100): %p\n", after_malloc);

    int difference = after_malloc - initial_brk;
    printf("difference: %d\n", difference);

    return 0;
}
