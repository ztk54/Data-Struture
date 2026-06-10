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
	for (int i = 0;i < n;i++)
	{
		//flag必须在每次循环都置为0
		int flag = 0;
		for (int j = 0;j < n - i - 1;j++)
		{
			if (arr[j] > arr[j + 1])
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

void _Merge_sort(int* arr, int left, int right, int* tmp)
{
	//递归
	if (left >= right)
	{
		return;
	}
	//根据mid不断划分为左右序列，[left,mid][mid+1,right]。
	int mid = (right - left) / 2 + left;
	_Merge_sort(arr, left, mid, tmp);
	_Merge_sort(arr, mid + 1, right, tmp);

	//使区间有序,注意这里的index不能等于0，哪个小哪个往前放
	//这里我在自己写的时候遇到了一个bug，tmp[begin1++] = arr[index++];，这条语句是错的，应该是把原数组里面begin的位置放到tmp那里
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
		{
			tmp[index++] = arr[begin1++];
		}
		else
		{
			tmp[index++] = arr[begin2++];
		}
	}
	//此时还有一个可能没有完全插入
	while (begin1 <= end1)
	{
		tmp[index++] = arr[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = arr[begin2++];
	}

	for (int i = left;i <= right;i++)
	{
		arr[i] = tmp[i];
	}
}

void Merge_sort(int* arr, int n)
{
	int* tmp = (int*)malloc(n * sizeof(int));
	if (tmp == NULL)
	{
		perror("Malloc Failed");
		return;
	}
	_Merge_sort(arr, 0, n - 1, tmp);
	free(tmp);
}

void my_qsort(int* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	//int keyi = hoare_qsort(arr, left, right);
	int keyi = lomuto_qsort(arr, left, right);
	my_qsort(arr, left, keyi - 1);
	my_qsort(arr, keyi + 1, right);
}

//hore版本找基准值
int hoare_qsort(int* arr, int left, int right)
{
	int keyi = left;
	left++;
	while (left <= right)
	{
		//注意这里条件都需要限定left<=right
		//从右往左走，找比基准值小的
		while (left <= right && arr[right] > arr[keyi])
		{
			right--;
		}
		//从左往右走，找比基准值大的
		while (left <= right && arr[left] < arr[keyi])
		{
			left++;
		}
		//注意这里如果没有后面的left和right操作有可能会造成死循环情况
		if (left <= right)
		{
			swap(&arr[left], &arr[right]);
			left++;
			right--;
		}
	}
	//交换right和keyi的位置
	swap(&arr[right], &arr[keyi]);
	return right;
}

int lomuto_qsort(int* arr, int left, int right)
{
	int keyi = left;
	int prev = left, cur = prev + 1;
	while (cur <= right)
	{
		if (arr[cur] < arr[keyi] && ++prev != cur)
		{
			swap(&arr[prev], &arr[cur]);
		}
		cur++;
	}
	swap(&arr[prev], &arr[keyi]);
	return prev;
}


void count_sort(int* arr, int n)
{
	//找到最大最小值
	int max = 0, min = 0;
	for (int i = 0;i < n;i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
		if (min > arr[i])
		{
			min = arr[i];
		}
	}

	//扩容得到count数组
	int range = max - min + 1;
	int* count = (int*)calloc(range, sizeof(int));
	if (count == NULL)
	{
		perror("Calloc Fail");
		exit(1);
	}
	for (int i = 0;i < n;i++)
	{
		count[arr[i] - min]++;
	}
	//还原
	int index = 0;
	for (int i = 0;i < range;i++)
	{
		while (count[i]--)
		{
			arr[index++] = i + min;
		}
	}
}

