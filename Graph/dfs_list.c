/****************************************************
\file   dfs_list.c
\author Jinseob Park
\par    email: 0814owl@gmail.com
\brief	DFS�� list�� ǥ���� ���α׷�
*****************************************************/
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50
typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
} GraphNode;

int visited[MAX_VERTICES];

typedef struct GraphType {
	int n;
	GraphNode* adj_list[MAX_VERTICES];
}GraphType;

// �׷��� �ʱ�ȭ 
void init(GraphType* g)
{
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
			g->adj_list[v] = 0;
}
// ���� ���� ����
void insert_vertex(GraphType* g)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "�׷���: ������ ���� �ʰ�");
		return;
	}
	g->n++;
}
// ���� ���� ����
void insert_edge(GraphType* g, int start, int end)
{
	GraphNode* node;
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "�׷���: ���� ��ȣ ����");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = end;
	node->link = g->adj_list[start];
	g->adj_list[start] = node;
}
// ���� ���� ����2
void insert_last_edge(GraphType* g, int start, int end)
{
	GraphNode* node, *head;
	if (start >= (g)->n || end >= (g)->n) {
		fprintf(stderr, "�׷���: ���� ��ȣ ����");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = end;
	node->link = NULL;
	head = g->adj_list[start];
	if (g->adj_list[start] == NULL)
		g->adj_list[start] = node;
	else {
		while (head->link != NULL)
		{
			head = head->link;
		}
		head->link = node;
	}
}
// ���� ����Ʈ�� ǥ���� �׷����� ���� ���� �켱 Ž��
void dfs_list(GraphType* g, int v)
{
	GraphNode* w;
	visited[v] = TRUE;   		// ���� v�� �湮 ǥ�� 
	printf("���� %d -> ", v);		// �湮�� ���� ���
	for (w = g->adj_list[v]; w; w = w->link)// ���� ���� Ž�� 
		if (!visited[w->vertex])
			dfs_list(g, w->vertex); //���� w���� DFS ���� ����
}
int main(void)
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	for (int i = 0; i < 4; i++)
		insert_vertex(g);
	insert_last_edge(g, 0, 1);
	insert_last_edge(g, 0, 2);
	insert_last_edge(g, 0, 3);
	insert_last_edge(g, 1, 0);
	insert_last_edge(g, 1, 2);
	insert_last_edge(g, 2, 0);
	insert_last_edge(g, 2, 1);
	insert_last_edge(g, 2, 3);
	insert_last_edge(g, 3, 0);
	insert_last_edge(g, 3, 2);

	printf("���� �켱 Ž��\n");
	dfs_list(g, 0);
	printf("\n");
	free(g);
	return 0;
}