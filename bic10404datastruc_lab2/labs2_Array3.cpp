#include <stdio.h>
#include <string.h>

int main() {
    int i, j, num[5];
    char star[5][50]; // Array of strings to store stars for each match
    
    for (i = 0; i < 5; i++) {
        printf("Please enter the score for match %d: ", i + 1);
        scanf("%d", &num[i]);
        
        // Initialize star string for each match
        memset(star[i], '*', num[i]);
        star[i][num[i]] = '\0'; // Null-terminate the string
    }
    
    for (i = 0; i < 5; i++) {
        printf("\n%d: %s", i + 1, star[i]);
    }
    
    return 0;
}
