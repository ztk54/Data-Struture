//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//void Rotate1(int nums[], int k, int n);
//void Rotate2(int nums[], int k, int n);
//void Rotate3(int nums[], int k, int n);
//
//void Reverse(int* nums, int n, int m)
//{
//	while (n < m)
//	{
//		int tem = nums[n];
//		nums[n] = nums[m];
//		nums[m] = tem;
//		n++;
//		m--;
//	}
//}
//
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
//	Rotate3(nums, k, n);
//	for (int i = 0;i < n;i++)
//	{
//		printf("%d ", nums[i]);
//	}
//	free(nums);
//	return 0;
//}
//
//void Rotate1(int nums[], int k, int n)
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
//
//void Rotate2(int nums[], int k, int n)
//{
//	k = k % n;//防止越界情况
//	Reverse(nums, 0, n - k - 1);
//	Reverse(nums, n - k, n - 1);
//	Reverse(nums, 0, n - 1);
//}
//
//void Rotate3(int nums[], int k, int n)
//{
//	k = k % n;
//	int* tem = (int*)malloc(n * sizeof(int));
//	for (int i = 0;i < n;i++)
//	{
//		tem[(i + 2) % n] = nums[i];
//	}
//	for (int i = 0;i < n;i++)
//	{
//		nums[i] = tem[i];
//	}
//	free(tem);
//}
