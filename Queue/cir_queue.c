/****************************************************
\file   cir_queue.c
\author Jinseob Park
\par    email: 0814owl@gmail.com
\brief	원형큐를 기본으로 표현
*****************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAX 8

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX];
}Cirque;

void initial(Cirque* q)
{
	q->front = 0;
	q->rear = 0;
}

int is_full(Cirque* q)
{
	return ((q->rear + 1) % MAX == q->front);
}

int is_empty(Cirque* q)
{
	return (q->front == q->rear);
}

void enqueue(Cirque* q, element item)
{
	if (is_full(q)) {
		printf("Err\n");
		exit(1);
	}
	else {
		q->rear = (q->rear + 1) % MAX;
		q->data[q->rear] = item;
	}
}

element dequeue(Cirque* q)
{
	if (is_empty(q))
	{
		printf("Err\n");
		exit(1);
	}
	else {
		q->front = (q->front+1) % MAX;
		return q->data[q->front];
	}
}

int main(void)
{
	Cirque que;
	initial(&que);

	enqueue(&que, 5);
	enqueue(&que, 50);
	enqueue(&que, 500);
	enqueue(&que, 5000);
	enqueue(&que, 50000);
	enqueue(&que, 500000);
	enqueue(&que, 5000000);

	printf("%d ", dequeue(&que));
	printf("%d ", dequeue(&que));
	printf("%d ", dequeue(&que));
	printf("%d ", dequeue(&que));
	printf("%d ", dequeue(&que));
	printf("%d ", dequeue(&que));
	printf("%d ", dequeue(&que));

	return 0;
}