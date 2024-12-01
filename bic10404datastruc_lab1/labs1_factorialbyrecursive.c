#include <stdio.h> // Include standard input-output library for printf and scanf functions.

// Recursive function to find factorial
int fact(int y) {
    if (y == 0) // Base case: if y is 0, factorial is 1.
        return 1;
    return y * fact(y - 1); // Recursive call to find factorial.
}

int main() {
    int x;

    printf("Enter a number to find factorial: "); // Prompt the user to enter a number.
    scanf("%d", &x); // Read the number entered by the user and store it in variable x.

    printf("The factorial of the number is %d\n", fact(x)); // Call the factorial function and display the result.

    return 0; // Indicates successful termination of the program.
}