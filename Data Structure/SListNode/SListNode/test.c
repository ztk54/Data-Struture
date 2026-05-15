#include "SListNode.h"

int main()
{
	SListNode *p = NULL;
	STLPushFront(&p, 1);
	STLPushFront(&p, 2);
	STLPushBack(&p, 3);
	STLPopBack(&p);
	SListPopFront(&p);
	if (STLFind(p, 1) == NULL)
	{
		printf("没找到\n");
	}
	else
	{
		printf("找到了\n");
	}
	SListInsertAfter(STLFind(p, 1), 6);
	STLPrint(p);
	return 0;
}