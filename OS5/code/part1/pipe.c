#include <stdio.h>
#include <unistd.h>

int main(){
	int fd[2];
	int res = pipe(fd);
	if (res==0){
		printf("Result is %d, successful.\n", res);
	} else {
		printf("Result is %d, failed.\n", res);
	}
	return 0;
}
