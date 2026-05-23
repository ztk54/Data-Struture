#include "Stack.h"

int main()
{
	Stack q;
	StackInit(&q);
	StackPush(&q, 1);
	StackPush(&q, 2);
	StackPush(&q, 3);
	StackPush(&q, 4);
	while (!IsStackEmpty(&q))
	{
		printf("%d ", StackTop(&q));
		StackPop(&q);
	}
	StackDestroy(&q);
	return 0;
}