#include "DListNode.h"

DListNode* ListCreate(LTDataType x)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	if (newnode == NULL)
	{
		perror("Malloc Failed");
		exit(1);
	}
	newnode->data = x;
	//这里出了个问题，前驱和后驱应该指向自己，不能置为空指针
	newnode->next = newnode->prev = newnode;
	return newnode;
}

//也可以接受一个双重指针的形式来进行初始化 
//void DLInit(DListNode **pphead)
//这种形式要我们先创建一个头节点对其初始化 
DListNode* DLInit()
{
	DListNode* phead = ListCreate(-1);
	return phead;
}

void ListDestory(DListNode** ppHead)
{
	DListNode* pcur = (*ppHead)->next;
	while (pcur != *ppHead)
	{
		DListNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	free(*ppHead);
	*ppHead = NULL;
}

bool IsEmpty(DListNode* pHead)
{
	assert(pHead);
	return pHead->next==pHead;
}

void ListPrint(DListNode* pHead)
{
	assert(pHead);
	DListNode* pcur = pHead->next;
	while (pcur != pHead)
	{
		printf("%d ->", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}

void ListPushBack(DListNode* pHead, LTDataType x)
{
	assert(pHead);
	DListNode* newnode = ListCreate(x);
	newnode->prev = pHead->prev;
	newnode->next = pHead;
	pHead->prev->next= newnode;
	pHead->prev = newnode;
}

void ListPushFront(DListNode* pHead, LTDataType x)
{
	assert(pHead);
	DListNode* newnode = ListCreate(x);
	newnode->next = pHead->next;
	newnode->prev = pHead;
	pHead->next->prev = newnode;
	pHead->next = newnode;
}

void ListPopBack(DListNode* pHead)
{
	assert(!IsEmpty(pHead));
	DListNode* pcur = pHead->prev;
	pcur->prev->next = pHead;
	pHead->prev = pcur->prev;
	free(pcur);
	pcur = NULL;
}

void ListPopFront(DListNode* pHead, LTDataType x)
{
	assert(!IsEmpty(pHead));
	DListNode* pcur = pHead->next;
	pHead->next = pcur->next;
	pcur->next->prev = pHead;
	free(pcur);
	pcur = NULL;
}

DListNode* ListFind(DListNode* pHead, LTDataType x)
{
	assert(pHead);
	DListNode* pcur = pHead->next;
	while (pcur != pHead)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}

// 双向链表在pos的前面进行插入
void ListInsert(DListNode* pos, LTDataType x)
{
	assert(pos);
	DListNode* newnode = ListCreate(x);
	newnode->next = pos;
	newnode->prev = pos->prev;
	pos->prev = newnode;
	newnode->prev->next = newnode;
}

void ListErase(DListNode* pos)
{
	assert(pos);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
}