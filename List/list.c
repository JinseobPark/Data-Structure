/****************************************************
\file   list.c
\author Jinseob Park
\par    email: 0814owl@gmail.com
\brief	linked list의 기본적인 표현.
*****************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node {
	element data;
	struct Node* link;
}Node;

Node* insert_first(Node* head, int item)
{
	Node *p = (Node*)malloc(sizeof(Node));
	p->data = item;
	p->link = head;
	head = p;
	return p;
}

Node* insert_pre(Node* head, Node* pre, int item)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = item;
	p->link = pre->link;
	pre->link = p;
	return head;
}


Node* delete_first(Node* head)
{
	Node* remove;
	if (head == NULL) return NULL;
	remove = head;
	head = remove->link;
	free(remove);
	return head;
}

Node* delete(Node* head, Node* pre)
{
	Node* remove;
	remove = pre;
	pre = remove->link;
	free(remove);
	return head;
}

Node* search(Node* head, element item)
{
	Node* p = head;
	while (p != NULL)
	{
		if (p->data == item) {
			printf("Find!\n");
			return p;
		}
		p = p->link;
	}
	printf("cant Find!\n");
	return NULL;
}

Node* concat_list(Node* node1, Node* node2)
{
	if (node1 == NULL) return node2;
	else if (node2 == NULL) return node1;
	else {
		Node* p = node1;
		while (p != NULL)
		{
			p = p->link;
		}
		p->link = node2;
	}

	return node1;
}

Node* insert(Node* head, int pos, int item)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = item;
	Node* tmp = head;
	for (int i = 2; i < pos; ++i)
	{
		if (tmp->link != NULL)
			tmp = tmp->link;
	}

	p->link = tmp->link;
	tmp->link = p;
	return head;
}

Node* reverse(Node* head)
{
	Node* phead, * tmp, *result;
	phead = head;
	result = NULL;
	while (phead != NULL)
	{
		tmp = result;
		result = phead;

		phead = phead->link;
		result->link = tmp;
	}

	return result;
}

void print(Node* head)
{
	Node* p = NULL;
	for (p = head; p != NULL; p = p->link)
	{
		printf("%d-> ", p->data);
	}
	printf("NULL\n");
}

int main(void)
{
	Node* head = NULL;

	head = insert_first(head, 10);
	head = insert_first(head, 20);
	head = insert_first(head, 30);
	print(head);
	head = insert_first(head, 50);
	print(head);
	head = insert_first(head, 40);
	print(head);
	head = insert(head, 2, 400);
	print(head);

	head = reverse(head);
	print(head);
	//printf("search 30 : %d", search(head, 30)->data);
	head = delete_first(head);
	print(head);
	head = delete_first(head);
	print(head);
	head = delete_first(head);
	print(head);
	head = delete_first(head);
	print(head);
	head = delete_first(head);
	print(head);
	return 0;
}