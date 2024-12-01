/* C program for Merge Sort */
#include <stdio.h>

void merge(int arr[], int left, int middle, int right);
void mergeSort(int arr[], int left, int right);
void printArray(int A[], int size);

/* Driver code */
int main()
{
	int arr[] = {7, 5, 3, 1, 8, 10, 4, 5, 2, 9};
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	
	printf("*** C program for Merge Sort ***\n"); 
	
    printf("Array size is %d\n",arr_size); 

	printf("\nGiven array is: \n");
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	printf("\nSorted array is: \n");
	printArray(arr, arr_size);
	
	printf("*** That's all, thank you ***");
	return 0;
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int left, int middle, int right)
{
	int arr1, arr2, merarr;
	int subarr1 = middle - left + 1;
	int subarr2 = right - middle;

	/* create temp arrays */
	int L[subarr1], R[subarr2];

	/* Copy data to temp arrays L[] and R[] */
	for (arr1 = 0; arr1 < subarr1; arr1++)
		L[arr1] = arr[left + arr1];
	for (arr2 = 0; arr2 < subarr2; arr2++)
		R[arr2] = arr[middle + 1 + arr2];

	/* Merge the temp arrays back into arr[l..r]*/
	arr1 = 0; // Initial index of first subarray
	arr2 = 0; // Initial index of second subarray
	merarr = left; // Initial index of merged subarray
	while (arr1 < subarr1 && arr2 < subarr2) 
	{
		if (L[arr1] <= R[arr2]) 
		{
			arr[merarr] = L[arr1];
			arr1++;
		}
		else {
			arr[merarr] = R[arr2];
			arr2++;
		}
		merarr++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (arr1 < subarr1) {
		arr[merarr] = L[arr1];
		arr1++;
		merarr++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (arr2 < subarr2) {
		arr[merarr] = R[arr2];
		arr2++;
		merarr++;
	}
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int left, int right)
{
	if (left < right) 
	{
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int middle = left + (right - left) / 2;

		// Sort first and second halves
		mergeSort(arr, left, middle);
		mergeSort(arr, middle + 1, right);

		merge(arr, left, middle, right);
	}
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
	int arr1;
	for (arr1 = 0; arr1 < size; arr1++)
		printf("%d ", A[arr1]);
	printf("\n");
}