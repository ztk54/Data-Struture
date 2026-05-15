#include "SListNode.h"

SListNode* BuySListNode(STLDataType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		printf("malloc fail!");
		exit(0);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void STLPrint(SListNode* plist)
{
	assert(plist);
	while (plist)
	{
		printf("%d -> ", plist->data);
		plist = plist->next;
	}
	printf("NULL");
}

void STLPushBack(SListNode** plist, STLDataType x)
{
	SListNode* NewNode = BuySListNode(x);
	if (*plist == NULL)
	{
		*plist = NewNode;
	}
	SListNode* p1 = *plist;
	while (p1->next)
	{
		p1 = p1->next;
	}
	p1->next = NewNode;
	NewNode->next = NULL;
}

void STLPushFront(SListNode** plist, STLDataType x)
{
	assert(plist);
	SListNode* NewNode = BuySListNode(x);
	NewNode->next = *plist;
	*plist = NewNode;
}

void STLPopBack(SListNode** plist)
{
	assert(plist);
	if ((*plist)->next == NULL)
	{
		free(*plist);
		*plist = NULL;
	}
	else
	{
		SListNode* pail = *plist;
		SListNode* pre = NULL;
		while (pail->next)
		{
			pre = pail;
			pail = pail->next;
		}
		pre->next = NULL;
		free(pail);
		pail = NULL;
	}
}

void SListPopFront(SListNode** plist)
{
	assert(plist && *plist);
	SListNode* tem = *plist;
	*plist = (*plist)->next;
	free(tem);
}

SListNode* STLFind(SListNode* plist, STLDataType x)
{
	assert(plist);
	SListNode* p = plist;
	while (p)
	{
		if (p->data == x)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

void SListInsertAfter(SListNode* pos, STLDataType x)
{
	assert(pos);
	SListNode* NewNode = BuySListNode(x);
	NewNode->next = pos->next;
	pos->next = NewNode;
}

void SListEraseAfter(SListNode* pos)
{
	assert(pos && pos->next);
	SListNode* tem = pos->next;
	pos->next = tem->next;
	free(tem);
	tem = NULL;
}

void SLTInsert(SListNode** pphead, SListNode* pos, STLDataType x)
{
	assert(pphead && pos);
	if (*pphead == pos)
	{
		pos->next = *pphead;
	}
	else
	{
		SListNode* p = *pphead;
		while (p->next != pos)
		{
			p = p->next;
		}
		SListNode* NewNode = BuySListNode(x);
		NewNode->next = p->next;
		p->next = NewNode;
	}
}

void SLTErase(SListNode** pphead, SListNode* pos)
{
	assert(pphead && pos);
	if (pos == *pphead)
	{
		SListPopFront(pphead);
	}
	SListNode* p = *pphead;
	while (p->next != pos)
	{
		p = p->next;
	}
	p->next = pos->next;
	free(pos);
	pos = NULL;
}

void SLTDestroy(SListNode** pphead)
{
	SListNode* pcur = *pphead;
	while (pcur)
	{
		SListNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}

