#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    struct rusage usage;
    if (getrusage(RUSAGE_SELF, &usage) == 0) {
        printf("RAM usage: %lu KB\n", usage.ru_maxrss);
    } else {
        printf("Can't access.\n");
        return 1;
    }
    return 0;
}
