#include "Seqlist.h"

void test0()
{
	SL s;
	InitSL(&s);
	//SLPushBack(&s, 1);
	//SLPushBack(&s, 2);
	//SLPushBack(&s, 3);
	//SLPushBack(&s, 5);
	SLPushFront(&s, 1);
	SLPushFront(&s, 2);
	SLPushFront(&s, 3);
	SLPushFront(&s, 4);
	SLInsert(&s, 1, 555);
	SLPrint(&s);
}

int main()
{
	test0();
	return 0;
}