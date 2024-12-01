#include<stdio.h> // Include standard input-output library for printf and scanf functions.

int main() {
    int x, fact = 1, n; // Declare integer variables x, fact, and n.

    printf("Enter a number to find factorial: "); // Prompt the user to enter a number.

    scanf("%d", &n); // Read the number entered by the user and store it in variable n.

    // Calculate factorial using a for loop.
    for(x = 1; x <= n; x++)
        fact = fact * x; // Multiply fact by x in each iteration.

    printf("Factorial of %d is: %d\n", n, fact); // Display the factorial of the entered number.

    return 0; // Indicates successful termination of the program.
}