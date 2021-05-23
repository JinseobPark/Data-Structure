/****************************************************
\file   stack_check_bracket.c
\author Jinseob Park
\par    email: 0814owl@gmail.com
\brief	stack을 이용하여 괄호의 여닫음을 체크하는 프로그램
*****************************************************/
#include <stdio.h>
#include <stdlib.h>
//#define MAX 10
typedef char element;
typedef struct {
	int top;
	int capacity;
	element *data;
}Stack;


void initial(Stack* s)
{
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}

int is_full(Stack* s)
{
	return (s->top == (s->capacity - 1));
}

int is_empty(Stack* s)
{
	return (s->top == -1);
}

void push(Stack* s, int item)
{
	if (is_full(s))
	{
		//printf("Already full stack \n");
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
		//return 0;
	}
	s->data[++(s->top)] = item;
}

int pop(Stack* s)
{
	if (is_empty(s))
	{
		printf("Already empty stack \n");
		return 0;
	}
	else {
		return s->data[(s->top--)];
	}
}

int peek(Stack* s)
{
	if (is_empty(s))
	{
		printf("Already empty stack \n");
		return 0;
	}
	else {
		return s->data[(s->top)];
	}
}

void printStack(Stack* s)
{
	int i;
	if (is_empty(s))
	{
		printf("Already empty stack \n");
		return;
	}
	for (i = 0; i < s->top; ++i)
	{
		printf("%d ", s->data[i]);
	}
	printf("\n");
}

int checking(char* check)
{
	Stack snack;
	char ch, open_ch;
	int i;
	initial(&snack);

	for (i = 0; i < strlen(check); ++i)
	{
		ch = check[i];
		switch (ch)
		{
		case '(':case'{':case'[':
			push(&snack, ch);
			break;
		case ')':case'}':case']':
			if (is_empty(&snack)) return 0;
			else
			{
				open_ch = pop(&snack);
				if ((open_ch == '(' && ch != ')') ||
					(open_ch == '{' && ch != '}') ||
					(open_ch == '[' && ch != ']'))
					return 0;
			}
			break;
		}
	}

	if (!is_empty(&snack)) return 0;
	return 1;
}

int main(void)
{
	char* str = "()a(s(w(g)r)j)5(r(c) )t{e}";


	if (checking(str) == 1) printf("success\n");
	else {
		printf("fail\n");
	}
	return 0;
}