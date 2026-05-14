#include "SListNode.h"

int main()
{
	SListNode *p = NULL;
	STLPushFront(&p, 1);
	STLPushFront(&p, 2);
	STLPushFront(&p, 3);
	STLPrint(p);
	return 0;
}