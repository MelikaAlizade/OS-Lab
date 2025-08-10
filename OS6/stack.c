#include <stdio.h>

void test_stack(int num) {
    int i;
    printf("Address of i: %p\n", &i);
    if (num < 100) {
        test_stack(num + 1);
    }
}

int main() {
    test_stack(0);
    return 0;
}
