#include "Heap.h"

int main()
{
	//HP hp;
	//HeapInit(&hp);
	//HeapPush(&hp, 50);
	//HeapPush(&hp, 10);
	//HeapPush(&hp, 30);
	//HeapPush(&hp, 20);
	//HeapPop(&hp);
	//HeapDestroy(&hp);

	int arr[] = { 10,20,15,60,40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, n);
	for (int i = 0;i < n;i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;		

}