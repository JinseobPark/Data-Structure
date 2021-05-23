/****************************************************
\file   stack_link.c
\author Jinseob Park
\par    email: 0814owl@gmail.com
\brief	스택을 linked list로 표현
*****************************************************/
#include <stdio.h>
#include <malloc.h>

typedef int element;
typedef struct Node {
	element data;
	struct Node* link;
}Node;

typedef struct {
	Node* top;
}StackType;

void init(StackType *s)
{
	s->top = NULL;
}

int is_empty(StackType* s)
{
	return (s->top == NULL);
}

int is_full(StackType* s)
{
	return 0;
}

void push(StackType* s, element item)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = item;
	p->link = s->top;
	s->top = p;
}

int pop(StackType* s)
{
	if (is_empty(s))
	{
		printf("emprt~~\n");
		return 0;
	}
	else {
		Node* temp = s->top;
		int result = temp->data;
		s->top = s->top->link;
		free(temp);
		return result;
	}
}

void print_stack(StackType* s)
{
	Node* p = s->top;
	while (p != NULL)
	{
		printf("%d ->", p->data);
		p = p->link;
	}
	printf("NULL \n");
}

int peek(StackType* s)
{
	if (is_empty)
	{
		printf("emprt~~\n");
		return 0;
	}
	else {
		return s->top->data;
	}
}


int main(void)
{
	StackType stack;
	init(&stack);
	push(&stack, 1);
	push(&stack, 3);
	push(&stack, 5);
	push(&stack, 7);
	print_stack(&stack);
	printf("%d ", pop(&stack));
	printf("%d ", pop(&stack));
	printf("%d ", pop(&stack));
	printf("%d ", pop(&stack));
	return 0;
}