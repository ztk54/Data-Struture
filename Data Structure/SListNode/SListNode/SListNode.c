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
