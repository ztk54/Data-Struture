#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef  int SLDataType;
typedef struct SeqList
{
	SLDataType* arr;
	int size;
	int capacity;
}SL;

void InitSL(SL* s);

void SLCheckCapacity(SL* s);

void SLPushBack(SL* s,SLDataType x);

void SLPushFront(SL* s, SLDataType x);

void SLPopBack(SL* s);

void SLPopFront(SL* s);

void SLPrint(SL* s);

void SLInsert(SL* s, int pos, SLDataType x);

void SLErase(SL* s, int pos, SLDataType x);

int Find(SL* s, SLDataType x);

void SLDestroy(SL* s);

