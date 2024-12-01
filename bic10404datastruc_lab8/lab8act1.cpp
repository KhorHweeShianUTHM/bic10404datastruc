#include <stdio.h>

int main()
{

	int size, sec_arr, num, temp, result, arr[25];

	printf("\n<<<<<< bubble Sort >>>>> \n\n");
	
	printf("How many numbers u are going to enter?: ");
	scanf("%d", &num);

	printf("\n<< Enter %d elements >>\n\n", num);
	// This loop would store the input numbers in array
	for (size = 0; size < num; size++)
	{
		printf("Element [%d] : ", size);
		scanf("%d", &arr[size]);
	}

	for (size = 0; size < num - 1; ++size) 
	{
		// loop to compare array elements
		for (sec_arr = 0; sec_arr < num - size - 1; sec_arr++)
		{
			// compare two adjacent elements 
			// change > to < to sort in descending order
			if (arr[sec_arr] < arr[sec_arr + 1])
			{
				// swapping occurs if elements     
				// are not in the intended order
				int temp = arr[sec_arr];
				arr[sec_arr] = arr[sec_arr + 1];
				arr[sec_arr + 1] = temp;
			}
		}
		printf("\n Pass %d --> ", size);
		
		for (result = 0; result < num; ++result) 
		{
			printf("%d  ", arr[result]);
		}
		printf("\n");
	}
	printf("\n\nOrder of Sorted elements: ");
	
	for (result = 0; result < num; ++result) 
	{
		printf("%d  ", arr[result]);
	}
	printf("\n");

	return 0;
}