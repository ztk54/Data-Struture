#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(int* x, int* y);
//直接插入排序
void InsertSort(int* arr, int n);
//希尔排序
void ShellSort(int* arr, int n);

//冒泡排序
void Bubble_sort(int* arr, int n);

//直接选择排序
void select_sort(int* arr, int n);

//归并排序
void _Merge_sort(int* arr, int left, int right, int* tmp,int n);
void Merge_sort(int* arr, int n);

//