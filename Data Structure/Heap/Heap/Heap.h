#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
typedef int HeapDataType;

typedef struct
{
	int* arr;
	int size;
	int capacity;
}HP;

void swap(int* x, int* y);

void HeapInit(HP* php);

void HeapDestroy(HP* php);

bool HeapEmpty(HP* php);

int HeapSize(HP* php);

HeapDataType HeapTop(HP* php);

void HeapPush(HP* php, HeapDataType x);

void HeapPop(HP* php);

void Adjustup(HeapDataType* arr, int child);

void Adjustdown(HeapDataType* arr, int parent, int n);

void HeapSort(int* arr, int n);

void CreatData();


