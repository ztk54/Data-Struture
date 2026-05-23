#include "Queue.h"

void QueueInit(Queue* q)
{
	q->phead = q->ptail = NULL;
}

void QueueDestroy(Queue* q)
{
	assert(q);
	QueueNode* pcur = q->phead;
	while (pcur)
	{
		QueueNode* next = pcur->next;
		free(pcur);
		//pcur = NULL;这里置空其实是浪费了，中间一部分理论上讲确实有可能为野指针，但是你都找不到了，所以置空意义不大，只在最后把头和尾置空就行了
		pcur = next;
	}
	q->phead = q->ptail = NULL;
}

bool IsQueueEmpty(Queue* q)
{
	assert(q);
	return q->phead ==NULL;
}

void QueuePush(Queue* q, QDataType data)
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(Queue));
	if (newnode == NULL)
	{
		perror("Malloc Failed");
		exit(0);
	}
	newnode->next = NULL;
	newnode->data = data;
	if (q->phead==NULL)
	{
		q->phead = q->ptail = newnode;
	}
	else
	{
		q->ptail->next = newnode;
		q->ptail = q->ptail->next;
		//q->ptail = newnode;两者等价
	}
}

void QueuePop(Queue* q)
{
	assert(!IsQueueEmpty(q));
	if (q->phead == q->ptail)
	{
		free(q->phead);
		q->phead = q->ptail = NULL;
	}
	else
	{
		QueueNode* next = q->phead->next;
		free(q->phead);
		q->phead = NULL;
		q->phead = next;
	}
}

QDataType QueueFront(Queue* q)
{
	return q->phead->data;
}

QDataType QueueBack(Queue* q)
{
	return q->ptail->data;
}

int QueueSize(Queue* q)
{
	assert(q);
	QueueNode* pcur = q->phead->next;
	int size = 0;
	while (pcur)
	{
		pcur = pcur->next;
		size++;
	}
	return 0;
}



