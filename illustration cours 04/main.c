#include <stdio.h>

void min_max(int a, int b, int *ptr_min, int *ptr_max);

int main(void) {
    int a = 190, b = 200;
    int min, max;

    printf("min = %d, max = %d\n", min, max);

    min_max(a, b, &min, &max);

    printf("min(%d, %d) = %d\n", a, b, min);
    printf("max(%d, %d) = %d\n", a, b, max);

    return 0;
}

void min_max(int a, int b, int *ptr_min, int *ptr_max) {
    if (a > b) {
        *ptr_min = b;
        *ptr_max = a;
    } else {
        *ptr_min = a;
        *ptr_max = b;
    }
}