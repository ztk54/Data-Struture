#include "sort.h"

int main()
{
	int arr[] = { 5,4,3,2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	//ShellSort(arr, n);
	//Bubble_sort(arr, n);
	//select_sort(arr, n);
	//Merge_sort(arr, n);
	for (int i = 0;i < n;i++)
	{
		printf("%d ", arr[i]);
	}
}