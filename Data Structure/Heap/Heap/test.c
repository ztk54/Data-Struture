#include "Heap.h"

int main()
{
	HP hp;
	HeapInit(&hp);
	HeapPush(&hp, 50);
	HeapPush(&hp, 10);
	HeapPush(&hp, 30);
	HeapPush(&hp, 20);
	HeapPop(&hp);
	HeapDestroy(&hp);
	return 0;		

}