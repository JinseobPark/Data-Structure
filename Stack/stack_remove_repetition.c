/****************************************************
\file   stack_remove_repetition.c
\author Jinseob Park
\par    email: 0814owl@gmail.com
\brief	stack�� �̿��Ͽ� �ݺ��Ǵ� ���ڸ� �����ϴ� ���α׷�
ex)
������ �Է��Ͻÿ� : 122233
��� : 123
*****************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
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

void RemoveRepeat(StackType* s)
{
	int i = 0;
	char input[MAXSIZE];
	StackType reverse;
	init_stack(&reverse);

	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%s", &input, MAXSIZE);

	//���ڰ� �ڿ� ���� ���ڿ� �ٸ��ٸ� ���ÿ� �Է��Ѵ�.
	while (input[i] != NULL)
	{
		if (input[i] != input[i + 1])
			push(s, input[i] - '0');
		i++;
	}

	//���� ������ �����´�.
	while (!is_empty(s))
	{
		push(&reverse, pop(s));
	}

	//������ �ϳ��� �����ϸ� ����Ѵ�.
	printf("���: ");
	while (!is_empty(&reverse))
	{
		printf("%d ", pop(&reverse));
	}
	free(reverse.data);
}

int main(void)
{
	StackType A;
	init_stack(&A);

	RemoveRepeat(&A);

	free(A.data);
	return 0;
}