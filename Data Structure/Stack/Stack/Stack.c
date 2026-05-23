#include "Stack.h"

void StackInit(Stack* ps)
{
	ps->capacity = ps->size = 0;
	ps->arr = NULL;
}

void StackDestroy(Stack* ps)
{
	//首先判空
	if (ps->arr)
		free(ps->arr);
	ps->arr = NULL;
	ps->capacity = ps->size = 0;
}

bool IsStackEmpty(Stack* ps)
{
	assert(ps);
	return ps->size == 0;
}

void StackPush(Stack* ps, StackDataType data)
{
	if (ps->capacity == ps->size)
	{
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		StackDataType* tem = (StackDataType*)realloc(ps->arr, newcapacity * sizeof(StackDataType));
		if (tem == NULL)
		{
			perror("Malloc Failed");
			exit(0);
		}
		ps->arr = tem;
		ps->capacity = newcapacity;
	}
	ps->arr[ps->size++] = data;
}

void StackPop(Stack* ps)
{
	assert(!IsStackEmpty(ps));
	ps->size--;
}

StackDataType StackTop(Stack* ps)
{
	assert(!IsStackEmpty(ps));
	return ps->arr[ps->size - 1];
}

int StackSize(Stack* ps)
{
	return ps->size;
}



