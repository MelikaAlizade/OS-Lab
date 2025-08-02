#include <stdio.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo info;
    if (sysinfo(&info) == 0) {
        printf("Total RAM: %lu\nFree RAM: %lu\n", info.totalram, info.freeram);
    } else {
	printf("Can't access.\n");
        return 1;
    }
    return 0;
}
