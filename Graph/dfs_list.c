/****************************************************
\file   dfs_list.c
\author Jinseob Park
\par    email: 0814owl@gmail.com
\brief	DFS를 list로 표현한 프로그램
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

// 그래프 초기화 
void init(GraphType* g)
{
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
			g->adj_list[v] = 0;
}
// 정점 삽입 연산
void insert_vertex(GraphType* g)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}
// 간선 삽입 연산
void insert_edge(GraphType* g, int start, int end)
{
	GraphNode* node;
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = end;
	node->link = g->adj_list[start];
	g->adj_list[start] = node;
}
// 간선 삽입 연산2
void insert_last_edge(GraphType* g, int start, int end)
{
	GraphNode* node, *head;
	if (start >= (g)->n || end >= (g)->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
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
// 인접 리스트로 표현된 그래프에 대한 깊이 우선 탐색
void dfs_list(GraphType* g, int v)
{
	GraphNode* w;
	visited[v] = TRUE;   		// 정점 v의 방문 표시 
	printf("정점 %d -> ", v);		// 방문한 정점 출력
	for (w = g->adj_list[v]; w; w = w->link)// 인접 정점 탐색 
		if (!visited[w->vertex])
			dfs_list(g, w->vertex); //정점 w에서 DFS 새로 시작
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

	printf("깊이 우선 탐색\n");
	dfs_list(g, 0);
	printf("\n");
	free(g);
	return 0;
}