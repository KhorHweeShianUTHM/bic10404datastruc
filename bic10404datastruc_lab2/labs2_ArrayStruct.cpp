#include <stdio.h>

#define size 3

struct number {
    int a;
    int b;
    int c;
};

typedef struct number Number;

int main() {
    Number arrInt[size];
    int i;

    for (i = 0; i < size; i++) {
        printf("Enter the value-x: ");
        scanf("%d", &arrInt[i].a);
        printf("Enter the value-y: ");
        scanf("%d", &arrInt[i].b);
        printf("Enter the value-z: ");
        scanf("%d", &arrInt[i].c);
    }

    printf("\nValues entered:\n");
    for (i = 0; i < size; i++) {
        printf("value-x index [%d] : %d\n", i, arrInt[i].a);
        printf("value-y index [%d] : %d\n", i, arrInt[i].b);
        printf("value-z index [%d] : %d\n", i, arrInt[i].c);
        printf("\n");
    }

    return 0;
}
