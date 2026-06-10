#include "sort.h"
//int main()
//{
//	int arr[] = { 5,4,3,2 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	//ShellSort(arr, n);
//	//Bubble_sort(arr, n);
//	//select_sort(arr, n);
//	//Merge_sort(arr, n);
//	//count_sort(arr, n);
//	my_qsort(arr, 0, n - 1);
//	for (int i = 0;i < n;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}


//归并排序外排序

int compare(const void* elem1, const void* elem2)
{
	return *(int*)elem1 - *(int*)elem2;
}

void Creat_number()
{
	int n = 1000;
	srand((unsigned int)time(0));
	const char* file = "data.txt";
	FILE* fout = fopen(file, "w");
	if (fout == NULL)
	{
		perror("Create Failed");
		return;
	}
	for (int i = 0;i < n;i++)
	{
		int x = rand() + i;
		fprintf(fout, "%d\n", x);
	}
	fclose(fout);
}

//从文件中读取n个数据并且排列成有序
int ReadNumSort(FILE* fout, int n, const char* file)
{
	//动态开辟空间排序
	int* arr = (int*)malloc(n * sizeof(int));
	int j = 0;
	int x = 0;
	if (arr == NULL)
	{
		perror("Malloc Failded");
		return 0;
	}
	for (int i = 0;i < n;i++)
	{
		if (fscanf(fout, "%d", &x) == EOF)
		{
			break;
		}
		arr[j++] = x;
	}
	qsort(arr, j, sizeof(int), compare);

	//将有序的数组写入file中
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("Open Failed");
		free(arr);
		return 0;
	}
	for (int i = 0;i < j;i++)
	{
		fprintf(fin, "%d\n", arr[i]);
	}
	free(arr);
	fclose(fin);
	return j;
}

void MergeFile(const char* file1, const char* file2, const char* mfile)
{
	//打开三个文件
	FILE* fout1 = fopen(file1, "r");
	FILE* fout2 = fopen(file2, "r");
	FILE* mfout = fopen(mfile, "w");
	if (fout1 == NULL)
	{
		perror("Open Failed");
		return;
	}
	if (fout2 == NULL)
	{
		perror("Open Failed");
		return;
	}
	if (mfout == NULL)
	{
		perror("Open Failed");
		return;
	}
	int x1 = 0;
	int x2 = 0;
	int ret1 = fscanf(fout1, "%d", &x1);
	int ret2 = fscanf(fout2, "%d", &x2);
	while (ret1 != EOF && ret2 != EOF)
	{
		if (x1 < x2)
		{
			fprintf(mfout, "%d\n", x1);
			ret1 = fscanf(fout1, "%d", &x1);
		}
		else
		{
			fprintf(mfout, "%d\n", x2);
			ret2 = fscanf(fout2, "%d", &x2);
		}
	}
	while (ret1 != EOF)
	{
		fprintf(mfout, "%d\n", x1);
		ret1 = fscanf(fout1, "%d", &x1);
	}
	while (ret2 != EOF)
	{
		fprintf(mfout, "%d\n", x2);
		ret2 = fscanf(fout2, "%d", &x2);
	}
	fclose(fout1);
	fclose(fout2);
	fclose(mfout);
}

int main()
{
	//Creat_number();
	int number = 200;
	const char* file1 = "file1.txt";
	const char* file2 = "file2.txt";
	const char* mfile = "mfile.txt";
	FILE* fout = fopen("data.txt", "r");
	if (fout == NULL)
	{
		perror("Open Failed");
		return;
	}
	ReadNumSort(fout, number, file1);
	ReadNumSort(fout, number, file2);

	while (1)
	{
		MergeFile(file1, file2, mfile);
		remove(file1);
		remove(file2);
		rename(mfile, file1);
		if (ReadNumSort(fout, number, file2) == 0)
		{
			break;
		}
	}
	fclose(fout);
	return 0;
}