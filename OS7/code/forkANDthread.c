#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int global_var;

int main() {
    global_var = 10;
    int local_var = 5;
    printf("Main before fork: global_var=%d, local_var=%d\n",
           global_var, local_var);
    int pid = fork();
    if (pid == 0) { 
        global_var += 10;
        local_var += 10;
        printf("Child: global_var=%d, local_var=%d\n",
               global_var, local_var);
        exit(0);
    } else {
        wait(NULL);
        printf("Parent: global_var=%d, local_var=%d\n",
               global_var, local_var);
    }
    return 0;
}
