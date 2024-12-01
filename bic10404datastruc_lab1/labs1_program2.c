#include <stdio.h> // Include standard input-output library for printf and scanf functions.

int main() {
    int a, b, c; // Declare integer variables a, b, and c to store the input numbers.
    int sum; // Declare integer variable sum to store the sum of the three numbers.

    printf("\n Welcome. This program adds\n"); // Print a welcome message.
    printf("three numbers. Enter three numbers\n"); // Prompt the user to enter three numbers.

    // Read three numbers entered by the user and store them in variables a, b, and c.
    scanf("%d %d %d", &a, &b, &c);

    sum = a + b + c; // Calculate the sum of the three numbers.

    printf("The total is: %d\n\n", sum); // Display the total sum.

    return 0; // Indicates successful termination of the program.
}