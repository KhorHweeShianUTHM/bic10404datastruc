#include <stdio.h>

int main() {
    int numbers[10] = {7, 2, 3, 4, 6, 5, 9, 1, 10, 8};
    int even[10], odd[10];
    int even_count = 0, odd_count = 0;

    // Separate even and odd numbers
    for (int i = 0; i < 10; i++) {
        if (numbers[i] % 2 == 0)
            even[even_count++] = numbers[i];
        else
            odd[odd_count++] = numbers[i];
    }

    // Print even numbers
    for (int i = 0; i < even_count; i++) {
        printf("%d ", even[i]);
    }

    // Print odd numbers
    for (int i = 0; i < odd_count; i++) {
        printf("%d ", odd[i]);
    }

    return 0;
}

// 2 4 6 10 8 7 3 5 9 1
// the first five number are even number
// next five number are odd number