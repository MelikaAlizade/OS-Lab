#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
	printf("Enter the address to the file.\n");
	return 1;
    }

    if(access(argv[1], R_OK) == 0 || access(argv[1], W_OK) == 0) {
	printf("File is accessible.\n");
    } else
	printf("The file does not exists.\n");

    return 0;
}
