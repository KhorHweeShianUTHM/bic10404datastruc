#include<stdio.h>

int main()
{

	int size, j, num, temp, k, min, arr[25];

	printf("\n<<<<<< Selection Sort >>>>> \n\n");

	printf("How many numbers u are going to enter?: ");
	scanf("%d", &num);

	printf("\n<< Enter %d elements >>\n\n", num);
	// This loop would store the input numbers in array
	
	for (size = 0; size < num; size++)
	{
		printf("Element [%d] : ", size);
		scanf("%d", &arr[size]);
	}


	for (size = 0; size < num - 1; size++)
	{
		min = size;
		
		for (sec_arr = size + 1; sec_arr < num; sec_arr++)
		{
			if (arr[sec_arr] < arr[min])
				min = sec_arr;
		}

		printf("\n location %d the min %d--> ", min, arr[min]);

		temp = arr[size];
		arr[size] = arr[min];
		arr[min] = temp;

		printf("\n Pass %d --> ", size);
		
		for (k = 0; k < num; k++)
		{
			printf(" %d", arr[k]);
		}
			
		printf("\n");
	}

	printf("\n\nOrder of Sorted elements: ");
	for (size = 0; size < num; size++)
	{
		printf(" %d", arr[size]);
	}
		
	return 0;
}