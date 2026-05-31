#define _CRT_SECURE_NO_WARNINGS
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

	//int arr[] = { 10,20,15,60,40 };
	//int n = sizeof(arr) / sizeof(arr[0]);
	//HeapSort(arr, n);
	//for (int i = 0;i < n;i++)
	//{
	//	printf("%d ", arr[i]);
	//}

	//十万个元素找最小的十个
	//CreatData();
	//FILE* fout = "data.txt";这样的写法是错误的
	FILE* fout = fopen("data.txt", "r");
	int k = 0;
	scanf("%d", &k);
	int* minheap = (int*)malloc(k * sizeof(int));
	for (int i = 0;i < k;i++)
	{
		fscanf(fout, "%d", &minheap[i]);
	}
	//对于minheap向下调整建堆
	for (int i = (k - 1 - 1) / 2;i > 0;i--)
	{
		Adjustdown(minheap, i, k);
	}
	//遍历剩下n-k个数据
	int x = 0;
	while (fscanf(fout, "%d", &x) != EOF)
	{
		if (x > minheap[0])
		{
			minheap[0] = x;
			Adjustdown(minheap, 0, k);
		}
	}
	for (int i = 0;i < k;i++)
	{
		printf("%d ", minheap[i]);
	}
	return 0;
}