#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int StackDataType;
typedef struct Stack
{
	StackDataType* arr;
	int size;
	int capacity;
}Stack;

void StackInit(Stack* ps);

void StackDestroy(Stack* ps);

bool IsStackEmpty(Stack* ps);

void StackPush(Stack* ps, StackDataType data);

void StackPop(Stack* ps);

StackDataType StackTop(Stack* ps);

int StackSize(Stack* ps);