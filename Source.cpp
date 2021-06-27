#include <stdio.h>
#include <conio.h>

void heapify(int arr[], int n, int i)		// To heapify a subtree rooted with node i which is an index in arr[]. n is size of heap
{
	int largest = i;						// Initialize largest as root
	int l = 2 * i + 1;						// left = 2*i + 1
	int r = 2 * i + 2;						 // right = 2*i + 2

	if (l < n && arr[l] > arr[largest])		// If left child is larger than root
		largest = l;

	if (r < n && arr[r] > arr[largest])		// If right child is larger than largest so far
		largest = r;

	if (largest != i)						// If largest is not root
	{
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;

		heapify(arr, n, largest);			// Recursively heapify the affected sub-tree
	}
}

void heapSort(int arr[], int n)				// main function to do heap sort
{
	for (int i = n / 2 - 1; i >= 0; i--)	// Build heap (rearrange array)
		heapify(arr, n, i);

	for (int i = n - 1; i > 0; i--)			// Build heap (rearrange array)
	{
		int temp = arr[0];					// Move current root to end - swap arr[0] and arr[i]
		arr[0] = arr[i];
		arr[i] = temp;

		heapify(arr, i, 0);					// call max heapify on the reduced heap
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	// int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arr[] = { 4, 5, 3, 10, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, n);

	printf("Sorted array is \n");
	printArray(arr, n);
	_getch();
}
