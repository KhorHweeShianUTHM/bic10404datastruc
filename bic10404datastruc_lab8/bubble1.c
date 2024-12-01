#include <stdio.h>

int main()
{
	int size, sec_arr, result, num, arr[25];
	int outer_loop = 0, temp, inner_loop;
	
	printf("\n<<<<<< buble Sort >>>>> \n\n");
	printf("How many numbers u are going to enter?: ");
	scanf("%d", &num);
	
	printf("\n<< Enter %d elements >>\n\n", num);
	// This loop would store the input numbers in array
	
	for(size = 0; size < num; size++)
	{
		printf("Element [%d] : ", size);
		scanf("%d", &arr[size]);
	}
	
	while(outer_loop < num - 1)
	{
		for(inner_loop = 0; inner_loop < num - outer_loop - 1; inner_loop++)
		{
			if(arr[inner_loop] > arr[inner_loop + 1])
			{
				temp = arr[inner_loop];
				arr[inner_loop] = arr[inner_loop + 1];
				arr[inner_loop + 1] = temp;
			}
		}
		printf("\n Pass %d --> ", size);
		for (result = 0; result < num; result++)
		{
			printf("%d  ", arr[result]);  
		}
		printf("\n");
		outer_loop++;
	}
	
	printf("\n\nOrder of Sorted elements: ");
	for (result = 0; result < num; ++result)
	{
		printf("%d  ", arr[result]);
	}
	printf("\n");
	
	return 0;
}