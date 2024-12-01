#include <stdio.h>

int main() {
    int a = 10;
    float b = 12.3;

    int *p;
    float *q;
    void *r;
    p = &a;
    q = &b;
    printf("%d\n", *p); // Output: 10
    r = p;
    // Dereferencing void pointer after casting to int *
    printf("%d\n", *r); // Output: 10

    return 0;
}