//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//void Rotate(int nums[], int k, int n);
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int* nums = (int*)malloc(n * sizeof(int));
//	for (int i = 0;i < n;i++)
//	{
//		scanf("%d", &nums[i]);
//	}
//	int k = 0;
//	scanf("%d", &k);
//	Rotate(nums, k, n);
//	free(nums);
//	return 0;
//}
//void Rotate(int nums[], int k, int n)
//{
//	k = k % n;
//	while (k--)
//	{
//		int temp = nums[n - 1];
//		for (int i = 0;i < n - 1;i++)
//		{
//			nums[i] = nums[i - 1];
//		}
//		nums[0] = temp;
//	}
//}