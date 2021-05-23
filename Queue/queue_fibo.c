/****************************************************
\file   queue_fibo.c
\author Jinseob Park
\par    email: 0814owl@gmail.com
\brief	피보나치를 queue를 이용하여 계산하는 프로그램
*****************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX_SIZE];
}QueueType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType* q)
{
	q->rear = 0;
	q->front = 0;
}

int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_SIZE == q->front);
}

int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

void enqueue(QueueType* q, int item)
{
	if (is_full(q))
	{
		error("Queue is full.");
		return;
	}
	q->rear = (q->rear + 1) % MAX_SIZE;
	q->data[(q->rear)] = item;
}

element dequeue(QueueType* q)
{
	if (is_empty(q))
	{
		error("Queue is empty.");
		return -1;
	}
	q->front = (q->front + 1) % MAX_SIZE;
	return q->data[q->front];
}

element peek(QueueType* q)
{
	if (is_empty(q))
	{
		error("Queue is empty.");
		return -1;
	}
	return q->data[q->rear];
}

int Fibo(QueueType* q, int n)
{
	int temp, i;

	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
	{
		for (i = 2; i <= n; ++i)
		{
			temp = dequeue(q);
			enqueue(q, temp + peek(q));
			printf("%d : %d \n", i, q->data[q->rear]);
		}
	}
	return q->data[q->rear];
}



int main(void)
{
	QueueType queue;
	int count;

	init_queue(&queue);

	printf("정수를 입력하시오: ");
	scanf("%d", &count);

	enqueue(&queue, 0);
	printf("0 : 0 \n");
	enqueue(&queue, 1);
	printf("1 : 1 \n");

	printf("result : %d\n", Fibo(&queue, count));

	return 0;
}
