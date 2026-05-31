#include "Heap.h"
#define _CRT_SECURE_NO_WARNINGS
void swap(int* x, int* y)
{
	int tem = *x;
	*x = *y;
	*y = tem;
}

void HeapInit(HP* php)
{
	php->arr = NULL;
	php->capacity = php->size = 0;
}

void HeapDestroy(HP* php)
{
	if (php->arr)
		free(php->arr);
	php->arr = NULL;
	php->capacity = php->size = 0;
}

bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}

int HeapSize(HP* php)
{
	return php->size;
}

HeapDataType HeapTop(HP* php)
{
	return php->arr[0];
}

void HeapPush(HP* php, HeapDataType x)
{
	assert(php);
	if (php->capacity == php->size)
	{
		int newCapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
		//这里原本的写法HeapDataType* tem = (HeapDataType*)malloc(php->capacity * sizeof(HeapDataType)); 
		//是错误的，newCapicity根本就没有用到
		//并且之前这里用的malloc也是错误，应该用realloc
		HeapDataType* tem = (HeapDataType*)realloc(php->arr, newCapacity * sizeof(HeapDataType));
		if (tem == NULL)
		{
			perror("Malloc Failed");
			exit(1);
		}
		php->arr = tem;
		php->capacity = newCapacity;
	}
	php->arr[php->size] = x;
	Adjustup(php->arr, php->size);
	php->size++;
}

void HeapPop(HP* php)
{
	assert(!HeapEmpty(php));
	swap(&php->arr[0], &php->arr[php->size - 1]);
	php->size--;
	Adjustdown(php->arr, 0, php->size);
}

void Adjustup(HeapDataType* arr, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		//大堆>  小堆<
		if (arr[child] > arr[parent])
		{
			swap(&arr[child], &arr[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void Adjustdown(HeapDataType* arr, int parent, int n)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		//大堆<  小堆>
		//child + 1 < n 的越界检查应该放在 前面，否则当 child + 1 == n 时会先访问 arr[child + 1] 导致越界
		if (child + 1 < n && arr[child] < arr[child + 1])
		{
			child++;
		}
		//大堆>  小堆<
		if (arr[child] > arr[parent])
		{
			swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//第一步将所需数组化堆的形式，大堆或小堆看具体是升序还是降序需求
//大堆是升序，小堆是降序
void HeapSort(int* arr, int n)
{
	//Adjustdown实现堆
	for (int i = (n - 1 - 1) / 2;i >= 0;i--)
	{
		Adjustdown(arr, i, n);
	}

	////Adjustup实现堆
	//for (int i = 0;i < 0;i++)
	//{
	//	Adjustup(arr, i);
	//}
	int end = n - 1;
	while (end)
	{
		swap(&arr[0], &arr[end]);
		Adjustdown(arr, 0, end);
		end--;
	}
}


//十万个元素找到最小的十个
void CreatData()
{
	int n = 100000;
	srand((unsigned int)time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen failed");
		return;
	}
	for (int i = 0;i < n;i++)
	{
		int x = (rand() + i) % n;
		fprintf(fin, "%d\n", x);
	}
	fclose(fin);
}

