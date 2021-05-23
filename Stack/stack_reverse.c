/****************************************************
\file   stack_reverse.c
\author Jinseob Park
\par    email: 0814owl@gmail.com
\brief	stack을 이용하여 배열을 뒤집는 함수
ex) 정수 배열의 크기 : 6
정수를 입력하시오 : 1 2 3 4 5 6
반전된 정수 배열 : 6 5 4 3 2 1
*****************************************************/
#include <stdio.h>
#include <stdlib.h>

int maxsize;
typedef int element;
typedef struct
{
	element* data;
	int capacity;
	int top;
} StackType;

void init_stack(StackType* s)
{
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}

void delete(StackType* s)
{
	free(s);
}

int is_empty(StackType* s)
{
	return (s->top == -1);
}

int is_full(StackType* s)
{
	return (s->top == (s->capacity - 1));
}

void push(StackType* s, element item)
{
	if (is_full(s))
	{
		s->capacity *= 2;
		s->data =
			(element*)realloc(s->data, s->capacity * sizeof(element));
	}
	s->data[++(s->top)] = item;
}

element pop(StackType* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "stack is empty\n");
		exit(1);
	}
	else
	{
		return s->data[(s->top)--];
	}
}

element peek(StackType* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "stack is empty\n");
		exit(1);
	}
	else
	{
		return s->data[s->top];
	}
}

void InputArray(StackType* s)
{
	int i, input;

	printf("정수를 입력하시오: ");
	for (i = 0; i < maxsize; ++i)
	{
		scanf_s("%d", &input);
		push(s, input);
	}
	printf("\n");
}

void OutputArray(StackType* s)
{
	int i;
	printf("반전된 정수 배열: ");
	for (i = 0; i < maxsize; ++i)
	{
		printf("%d ", pop(s));
	}
	printf("\n");
}

int main(void)
{
	StackType A;

	init_stack(&A);

	printf("정수 배열의 크기: ");
	scanf_s("%d", &maxsize);

	InputArray(&A);
	OutputArray(&A);

	free(A.data);
	return 0;
}