#include <stdio.h>
#include <stdlib.h>

int main() {
    int count, num_elements, search, array[100];

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
	
	for (count = 0; count < num_elements; count++) {
		if (array[count] == search) { /* If required element is found */
			printf("%d is present at location %d.\n", search, count + 1);
			break;
		}
  	}
  	
	if (count == num_elements) {
		printf("%d isn't present in the array.\n", search);
	}
	  
  return 0;
}