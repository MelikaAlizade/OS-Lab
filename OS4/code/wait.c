#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main () {
    pid_t pid = fork();
    if(pid==0){
        for(int i=1; i<=100; i++){
            printf("%d ",i);
        }
    } else {
        wait(NULL);
        printf("\nParent: child process has finished!\n");
    }
    return 0;
}
