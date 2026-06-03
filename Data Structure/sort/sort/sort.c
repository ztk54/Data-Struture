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

void Bubble_sort(int* arr, int n)
{
	int flag = 0;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n - i - 1;j++)
		{
			if (arr[j] < arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}

void select_sort(int* arr, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int maxi = begin;
		int mini = begin;
		for (int i = begin + 1;i <= end;i++)
		{
			if (arr[i] > arr[maxi])
			{
				maxi = i;
			}
			if (arr[i] < arr[mini])
			{
				mini = i;
			}
		}
		//注意这里的交换容易出现问题，比如说我们先交换begin和mini，如果这时候begin==maxi
		//那么我们第一次交换之后就会让原本的maxi对应的是最小值，再次与end交换就不能得到正确的效果
		//因为我们就让maxi先指向mini，mini与begin交换之后，maxi对应的自然就是我们找到的最大值
		//同理如果先交换maxi和end，那我也需要判断end是否与mini相等
		if (begin == maxi)
		{
			maxi = mini;
		}
		swap(&arr[mini], &arr[begin]);
		swap(&arr[maxi], &arr[end]);

		//另一种写法
		//if (end == mini)
		//{
		//	mini = maxi;
		//}
		//swap(&arr[maxi], &arr[end]);
		//swap(&arr[mini], &arr[begin]);

		end--;
		begin++;
	}
}

