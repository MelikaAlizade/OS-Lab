#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(){
	int fd[2];
	pipe(fd);
	int pid = fork();
	if(pid == 0){
		close(fd[1]);
		char msg[20];
		read(fd[0], msg, sizeof(msg));
		printf("The msg that recieved: %s\n", msg);
		close(fd[0]);
	} else {
		close(fd[0]);
		char msg[] = "Hello World";
		write(fd[1], msg, strlen(msg) + 1);
		printf("the msg that sent: %s\n", msg);
		close(fd[1]);
		wait(NULL);
	}
	return 0;
}

