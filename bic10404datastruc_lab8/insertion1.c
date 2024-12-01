#include <stdio.h>

int main()
{
	
 	int size, sec_arr, result, num, temp, key, arr[25];

	printf("\n<<<<< Insertion Sort >>>>>\n\n");

	printf("How many numbers u are going to enter?: ");
	scanf("%d", &num);

	printf("\n<< Enter %d elements >>\n\n", num);
	// This loop would store the input numbers in array

	for (size = 0; size < num; size++)
	{
		printf("Element [%d] : ", size);
		scanf("%d", &arr[size]);
	}

	for (size = 1; size < num; size++)
	{
		key = arr[size];
		sec_arr = size - 1;

		while ((arr[sec_arr] > key) && (sec_arr >= 0))
		{
			arr[sec_arr + 1] = arr[sec_arr]; //shsizeft
			sec_arr = sec_arr - 1;
		}
		arr[sec_arr + 1] = key;

		printf("\nPass %d --> ", size);

		for (result = 0; result < num; result++)
		{
			printf(" %d", arr[result]);
		}
	}

	printf("\n\nOrder of Sorted elements: ");
	
	for (size = 0; size < num; size++)
	{
		printf(" %d", arr[size]);
	}
		
	return 0;
}
