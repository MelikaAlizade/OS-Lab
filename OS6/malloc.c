#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MyStruct {
    int a;
    int b;
    char name[20];
};

int main() {

    struct MyStruct *ptr = (struct MyStruct *) malloc(sizeof(struct MyStruct));

    ptr->a = 10;
    ptr->b = 20;
    strcpy(ptr->name, "melika");

    printf("--before using free--\n");
    printf("MyStruct address = %p\n",ptr);
    printf("a = %d\n", ptr->a);
    printf("b = %d\n", ptr->b);
    printf("name = %s\n", ptr->name);

    free(ptr);

    printf("--after using free--\n");
    printf("MyStruct address = %p\n",ptr);
    printf("a = %d\n", ptr->a);
    printf("b = %d\n", ptr->b);
    printf("name = %s\n", ptr->name);

    return 0;
}
