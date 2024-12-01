#include <stdio.h>
#include <stdlib.h>

int main() {
    int count, first, last, middle, num_elements, search, array[100];

    // Prompt user to enter the number of elements
    printf("Enter number of elements: ");
    scanf("%d", &num_elements);

    // Input elements from the user
    printf("\nEnter %d integers:\n\n", num_elements);
    for (count = 0; count < num_elements; count++) {
        printf("Number %d: ", count + 1);
        scanf("%d", &array[count]);
    }

    // Display the integers entered
    printf("\nInteger numbers in the list:\n");
    for (count = 0; count < num_elements; count++) {
        printf("| %d ", array[count]);
    }
    printf("|\n");

    // Prompt user to enter the value to find
    printf("\nEnter value to find: ");
    scanf("%d", &search);

    // Initialize variables for binary search
    first = 0;
    last = num_elements - 1;
	middle = (first + last) / 2; // Calculate middle index
    
	while (first <= last) {
        printf("Middle Location is %d.\n", middle + 1);

        if (array[middle] == search) {
            printf("%d found at location %d.\n", search, middle + 1);
            break;
        } else if (array[middle] < search) {
            first = middle + 1; // Search in the upper half
        } else {
            last = middle - 1; // Search in the lower half
        }
    }

    if (first > last) {
        printf("Not found! %d isn't present in the list.\n", search);
    }

    return 0;
}