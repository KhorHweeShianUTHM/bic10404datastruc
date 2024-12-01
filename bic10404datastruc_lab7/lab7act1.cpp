#include <stdio.h>

int main() {
    char character[10] = {'A', 'B', 'B', 'D', 'C', 'D', 'C', 'A', 'C', 'B'};
    char search, ans;
    int count, total = 0;
    
    do{
    	printf("\n");
    	printf("\t***\n");
    	printf("\tCharacters in the list: ");
    	for (count = 0; count < 10; count++) {
    	    printf(" %c |", character[count]);
    	}
    	printf("\n");
    	printf("\t***\n");
    	

    	printf("\nEnter character to find: ");
    	scanf(" %c", &search);

    	for (count = 0; count < 10; count++) {
    	    if (character[count] == search) {
     	       total++;
     	   }
    	}

    	if (total > 0) {
    	    printf("\n>> Total occur of '%c' in the list: %d\n", search, total);
    	} else {
     	   printf("\n>> '%c' is not found in the list.\n", search);
    	}
    
    	printf("\nDo you want to run program again (Y/N)? ");
    	scanf(" %c", &ans);
	} while(ans=='Y'|| ans=='y');
	
	printf("\nExit program...");
	
	return 0;
}