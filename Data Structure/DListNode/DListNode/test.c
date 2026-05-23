#include "DListNode.h"

int main()
{
	DListNode* plist = DLInit();
	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);
	DListNode* pos = ListFind(plist, 2);
	ListInsert(pos, 111);
	ListDestory(&plist);
	return 0;
}