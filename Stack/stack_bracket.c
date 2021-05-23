/****************************************************
\file   stack_bracket.c
\author Jinseob Park
\par    email: 0814owl@gmail.com
\brief	stack을 이용하여 괄호번호를 체크하는 함수
ex) 
수식 : ((())(()))
괄호 수 : 1 2 3 3 2 4 5 5 4 1
*****************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef char element;
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

void InputArray(StackType* s)
{
	int i = 0, count = 1;
	char input[MAXSIZE];
	printf("수식: ");
	scanf_s("%s", &input, MAXSIZE);

	printf("괄호 수: ");
	while (input[i] != NULL)
	{
		if (input[i] == '(')
		{
			push(s, count);
			printf("%d ", count);
			count++;
		}
		else if (input[i] == ')')
		{
			printf("%d ", pop(s));
		}
		i++;
	}
	printf("\n");
}

int main(void)
{
	StackType A;

	init_stack(&A);

	InputArray(&A);

	free(A.data);
	return 0;
}