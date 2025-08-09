#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main () {
    int ret = fork();
    if(ret==0){
        printf("I am the child.\n");
    } else {
        wait(NULL);
        printf("I am the parent.\n");
    }
    return 0;
}
