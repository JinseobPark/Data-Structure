/****************************************************
\file   queue.c
\author Jinseob Park
\par    email: 0814owl@gmail.com
\brief	큐를 기본으로 표현
*****************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX];
}Que;

void initial(Que* q)
{
	q->front = -1;
	q->rear = -1;
}

int is_full(Que* q)
{
	return (q->rear == (MAX - 1));
}

int is_empty(Que* q)
{
	return (q->rear == q->front);
}

void enqueue(Que* q, int item)
{
	if (is_full(q))
	{
		printf("full!!!\n");
		exit(1);
	}
	q->data[++(q->rear)] = item;
}

int dequeue(Que* q)
{
	if (is_empty(q))
	{
		printf("empty!!!\n");
		exit(1);
	}
	return q->data[++(q->front)];
}

int main(void)
{
	int item = 0;
	Que qu;
	initial(&qu);

	enqueue(&qu, 10);
	enqueue(&qu, 30);
	enqueue(&qu, 50);
	enqueue(&qu, 60);
	enqueue(&qu, 70);
	enqueue(&qu, 40);

	printf("%d ", dequeue(&qu));
	printf("%d ", dequeue(&qu));
	printf("%d ", dequeue(&qu));
	printf("%d ", dequeue(&qu));
	printf("%d ", dequeue(&qu));
	printf("%d ", dequeue(&qu));

	return 0;
}