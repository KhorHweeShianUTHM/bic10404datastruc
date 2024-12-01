#include <stdio.h>

int main() {
    int m = 10, n = 5;
    int *mp, *np;

    mp = &m;
    printf("\nPrint the address of m: %p", (void *)&mp);

    np = &n;
    printf("\nPrint the address of n: %p", (void *)&np);

    printf("\nPrint the value of m from mp: %d", *mp);
    printf("\nPrint the value of n from np: %d", *np);

    printf("\nPrint m + n from mp and np: %d", *mp + *np);

    return 0;
}