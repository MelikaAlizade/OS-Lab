#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	int fd[2];
	pipe(fd);
	int pid = fork();
	if (pid == 0) {
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		execlp("wc", "wc", NULL);
	} else {
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execlp("ls", "ls", NULL);
	}
	return 0;
}

