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

