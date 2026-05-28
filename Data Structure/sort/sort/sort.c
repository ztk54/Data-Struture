#include "sort.h"

void swap(int* x, int* y)
{
	int tem = *x;
	*x = *y;
	*y = tem;
}

void InsertSort(int* arr, int n)
{
	//这里循环条件是i<n-1
	for (int i = 0;i < n - 1;i++)
	{
		int end = i;
		int tem = arr[end + 1];
		//循环条件不能写为end，end起初为0
		while (end >= 0)
		{
			if (arr[end] > tem)
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = tem;
	}
}

void ShellSort(int* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0;i < n - gap;i++)
		{
			int end = i;
			int tem = arr[end + gap];
			while (end >= 0)
			{
				if (arr[end] > tem)
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tem;
		}
	}
}
