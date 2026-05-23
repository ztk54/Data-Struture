#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int LTDataType;
typedef struct DListNode
{
	LTDataType data;
	struct DListNode* next;
	struct DListNode* prev;
}DListNode;


DListNode* ListCreate(LTDataType x);

DListNode* DLInit();

void ListDestory(DListNode** ppHead);

bool IsEmpty(DListNode* pHead);

void ListPrint(DListNode* pHead);

void ListPushFront(DListNode* pHead, LTDataType x);

void ListPopBack(DListNode* pHead);

void ListPushBack(DListNode* pHead, LTDataType x);

void ListPopFront(DListNode* pHead, LTDataType x);

DListNode* ListFind(DListNode* pHead, LTDataType x);

// 双向链表在pos的前面进行插入
void ListInsert(DListNode* pos, LTDataType x);

void ListErase(DListNode* pos);
