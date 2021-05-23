/****************************************************
\file   deque.c
\author Jinseob Park
\par    email: 0814owl@gmail.com
\brief	deque를 기본으로 표현
*****************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAX 8

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX];
}Deque;

void initial(Deque* d)
{
	d->front = 0;
	d->rear = 0;
}

int is_full(Deque* d)
{
	return ((d->rear + 1) % MAX == d->front);
}

int is_empty(Deque* d)
{
	return (d->rear  == d->front);
}

void add_front(Deque* d, element item)
{
	if (is_full(d))
	{
		printf("Err1\n");
		exit(1);
	}
	d->data[d->front] = item;
	d->front = (d->front - 1 + MAX) % MAX;
}

void add_rear(Deque* d, element item)
{
	if (is_full(d))
	{
		printf("Err2\n");
		exit(1);
	}
	d->rear = (d->rear + 1) % MAX;
	d->data[d->rear] = item;
}

int delete_front(Deque* d)
{
	if (is_empty(d))
	{
		printf("Err3\n");
		exit(1);
	}
	d->front = (d->front + 1) % MAX;
	return d->data[d->front];
}

int delete_rear(Deque* d)
{
	int prev = d->rear;
	if (is_empty(d))
	{
		printf("Err4\n");
		exit(1);
	}
	d->rear = (d->rear - 1 + MAX) % MAX;
	return d->data[prev];
}


int main(void)
{
	Deque deq;
	initial(&deq);

	add_front(&deq, 10);
	add_front(&deq, 20);
	add_front(&deq, 30);
	add_front(&deq, 40);
	add_rear(&deq, 50);
	add_rear(&deq, 60);

	printf("%d ", delete_front(&deq));
	printf("%d ", delete_front(&deq));
	printf("%d ", delete_front(&deq));
	printf("%d ", delete_front(&deq));
	printf("%d ", delete_front(&deq));
	printf("%d ", delete_front(&deq));
	return 0;
}