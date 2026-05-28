#include "sort.h"

int main()
{
	int arr[] = { 9,6,2,7,1,2,10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	ShellSort(arr, n);
	for (int i = 0;i < n;i++)
	{
		printf("%d ", arr[i]);
	}
}