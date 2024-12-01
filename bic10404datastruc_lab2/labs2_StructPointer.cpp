#include <stdio.h>

struct number {
    int x;
    int y;
    int sum;
};

typedef struct number num;

int main() {
    num val;
    num *pval;
    pval = &val;
    
    val.x = 150;
    val.y = 200;
    val.sum = val.x + val.y;
    
    printf("\nValue of x : %d ", val.x);
    printf("\nValue of y : %d ", val.y);
    printf("\nValue of sum : %d ", val.sum);
    
    printf("\nValue of x : %d ", pval->x);
    printf("\nValue of y : %d ", pval->y);
    printf("\nValue of sum : %d ", pval->sum);
    
    pval->x = 15;
    pval->y = 20;
    pval->sum = pval->x + pval->y;
    
    printf("\n\n****************************\n\n");
    
    printf("\nValue of x : %d ", val.x);
    printf("\nValue of y : %d ", val.y);
    printf("\nValue of sum : %d ", val.sum);
    
    printf("\nValue of x : %d ", pval->x);
    printf("\nValue of y : %d ", pval->y);
    printf("\nValue of sum : %d ", pval->sum);
    
    return 0;
}
