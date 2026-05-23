#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QDataType;
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue
{
	QueueNode* phead;
	QueueNode* ptail;
}Queue;

void QueueInit(Queue* q);

void QueueDestroy(Queue* q);

bool IsQueueEmpty(Queue* q);

void QueuePush(Queue* q, QDataType data);

void QueuePop(Queue* q);

QDataType QueueFront(Queue* q);

QDataType QueueBack(Queue* q);

int QueueSize(Queue* q);

