#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int ret = fork();
    if (ret == 0) {
        // ...
        return 23;
    } else {
        int rc = 0;
        wait(&rc);
        printf("return code is %d\n", WEXITSTATUS(rc));
    }
    return 0;
}