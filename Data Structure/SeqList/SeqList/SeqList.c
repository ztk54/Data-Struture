#include "Seqlist.h"

void InitSL(SL* s)
{
	s->capacity = 0;
	s->size = 0;
	s->arr = NULL;
}

void SLCheckCapacity(SL* s)
{
	if (s->capacity == s->size)
	{
		int newcapacity = s->capacity == 0 ? 4 : 2 * s->capacity;
		SLDataType* tem = realloc(s->arr, newcapacity * sizeof(SLDataType));
		if (tem == NULL)
		{
			perror("realloc fail");
			exit(0);
		}
		s->arr = tem;
		s->capacity = newcapacity;
	}
}

void SLPushBack(SL* s, SLDataType x)
{
	SLCheckCapacity(s);
	s->arr[s->size++] = x;
}

void SLPushFront(SL* s, SLDataType x)
{
	assert(s != NULL);
	SLCheckCapacity(s);
	for (int i = s->size;i > 0;i--)
	{
		s->arr[i] = s->arr[i - 1];
	}
	s->arr[0] = x;
	s->size++;
}

void SLPopBack(SL* s)
{
	assert(s->size && s);
	s->size--;
}

void SLPopFront(SL* s)
{
	assert(s->size && s);
	for (int i = 0;i < s->size - 1;i++)
	{
		s->arr[i] = s->arr[i + 1];
	}
	s->size--;
}

void SLPrint(SL* s)
{
	for (int i = 0;i < s->size;i++)
	{
		printf("%d ", s->arr[i]);
	}
}

void SLInsert(SL* s, int pos, SLDataType x)
{
	assert(s);
	assert(pos >= 0 && pos <= s->size);
	for (int i = s->size;i > pos;i--)
	{
		s->arr[i] = s->arr[i - 1];
	}
	s->arr[pos] = x;
	s->size++;
}

void SLErase(SL* s, int pos, SLDataType x)
{
	assert(s);
	assert(pos >= 0 && pos <= s->size);
	for (int i = pos;i < s->size;i++)
	{
		s->arr[i] = s->arr[i + 1];
	}
	s->size--;
}

int Find(SL* s, SLDataType x)
{
	for (int i = 0;i < s->size;i++)
	{
		if (s->arr[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SLDestroy(SL* s)
{
	if (s->arr)
		free(s->arr);
	s->capacity = 0;
	s->size = 0;
}
