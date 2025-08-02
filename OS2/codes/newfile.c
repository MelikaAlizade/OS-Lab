#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int file = open("oslab2.txt", O_WRONLY | O_CREAT | O_TRUNC);
    if (file < 0) {
        perror("Can't open the file.\n");
        return 1;
    }

    long written = write(file, "Melika Alizadeh & Elina Hozhabri\n", 34);
    close(file);
    if (written < 0) {
        perror("Can't write to the file.\n");
        return 1;
    }
    return 0;
}
