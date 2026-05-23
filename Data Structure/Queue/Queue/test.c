#include "Queue.h"

int main()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueueNode* pcur = q.phead;
	while (pcur)
	{
		QueueNode* next = pcur->next;
		printf("%d ", pcur->data);
		QueuePop(&q);
		pcur = next;
	}
}