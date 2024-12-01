#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Recursive function to check if a number is palindrome
// A palindrome is a sequence of characters that reads the same forwards and backwards
bool isPalindrome(char number[], int start, int end) {
    // Base case: if start and end pointers have crossed each other
    if (start >= end)
        return true;

    // Check if the digits at start and end positions are equal
    if (number[start] != number[end])
        return false;

    // Recur for the remaining digits
    return isPalindrome(number, start + 1, end - 1); // Recursive function 
}

int main() {
    char number[20];
    printf("Enter a positive integer: ");
    scanf("%s", number);

    int length = strlen(number);

    // Check if the number is a palindrome
    if (isPalindrome(number, 0, length - 1))
        printf("The number is a palindrome.\n");
    else
        printf("The number is not a palindrome.\n");

    return 0;
}