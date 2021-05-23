/****************************************************
\file   queue_link.c
\author Jinseob Park
\par    email: 0814owl@gmail.com
\brief	큐를 linked list로 표현
*****************************************************/
#include <stdio.h>
#include <malloc.h>

typedef int element;
typedef struct Node {
	element data;
	struct Node* link;
}Node;

typedef struct {
	Node* front, * rear;
}Queue;

void init(Queue* q)
{
	q->front = NULL;
	q->rear = NULL;
}

int is_empty(Queue* q)
{
	return (q->front == NULL);
}

int is_full(Queue* q)
{
	return 0;
}

void enqueue(Queue* q, element item)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = item;
	p->link = NULL;
	if (is_empty(q))
	{
		q->front = p;
		q->rear = p;
	}
	else {
		q->rear->link = p;
		q->rear = p;
	}
}

element dequeue(Queue* q)
{
	if (is_empty(q))
	{
		printf("Error!\n");
		return 0;
	}
	else {
		Node* temp = q->front;
		element result = temp->data;
		q->front = q->front->link;
		if (q->front == NULL)
			q->rear = NULL;
		free(temp);
		return result;
	}
}

void print(Queue* q)
{
	Node* temp = q->front;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->link;
	}
	printf("NULL\n");
}

int main(void)
{
	Queue que;
	init(&que);

	enqueue(&que, 1);
	enqueue(&que, 10);
	enqueue(&que, 100);
	print(&que);
	dequeue(&que);
	dequeue(&que);
	dequeue(&que);
	print(&que);

	return 0;
}