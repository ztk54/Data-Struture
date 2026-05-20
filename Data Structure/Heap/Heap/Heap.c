#include "Heap.h"

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
		HeapDataType* tem = (HeapDataType*)malloc(php->capacity * sizeof(HeapDataType));
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
	assert(!HeapEmpty);
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
		if (arr[child] < arr[child + 1] && child + 1 < n)
		{
			child++;
		}
		if (arr[child] < arr[parent])
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


