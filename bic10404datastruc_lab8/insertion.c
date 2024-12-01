#include <stdio.h>

int main()
{

	int size, sec_arr, result, num, temp, arr[25], key;

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

	for (sec_arr = 1; sec_arr < num; sec_arr++)
	{
		key = arr[sec_arr];
		
		for (result = sec_arr; result > 0; result--)
		{
			if (arr[result - 1] <= key) 
			{
				break;
			}
			arr[result] = arr[result - 1];
		}
		
		arr[result] = key;
		printf("\nPass %d --> ", sec_arr);
		
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
