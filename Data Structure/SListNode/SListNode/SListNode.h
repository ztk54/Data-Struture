#pragma once
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef int STLDataType;

typedef struct SListNode
{
	struct SlistNode* next;
	STLDataType data;
}SListNode;

SListNode* BuySListNode(STLDataType x);

void STLPrint(SListNode* plist);

void STLPushBack(SListNode** plist, STLDataType x);

void STLPushFront(SListNode** plist, STLDataType x);

void STLPopBack(SListNode** plist);

void SListPopFront(SListNode** plist);

SListNode* STLFind(SListNode* plist, STLDataType x);

void SListInsertAfter(SListNode* pos, STLDataType x);

void SListEraseAfter(SListNode* pos);

void SLTInsert(SListNode** pphead, SListNode* pos, STLDataType x);

void SLTErase(SListNode** pphead, SListNode* pos);

void SLTDestroy(SListNode** pphead);