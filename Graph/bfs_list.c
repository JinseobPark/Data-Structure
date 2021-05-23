/****************************************************
\file   bfs_list.c
\author Jinseob Park
\par    email: 0814owl@gmail.com
\brief	BFS�� list�� ǥ���� ���α׷�
*****************************************************/
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct { // ť Ÿ��
	element  queue[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

// ���� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ���� ���� ���� �Լ�
void queue_init(QueueType* q)
{
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// ���� �Լ�
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

// ���� �Լ�
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}


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
void graph_init(GraphType* g)
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
void insert_edge1(GraphType* g, int start, int end)
{
	GraphNode* node, *head;
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "�׷���: ���� ��ȣ ����");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = end;
	node->link = NULL;

	head = g->adj_list[start];
	if (head == NULL)
		head = node;
	else {
		while (head->link != NULL)
		{
			head = head->link;
		}
		head->link = node;
	}
	//node->link = g->adj_list[start];
	g->adj_list[start] = head;
}

void bfs_list(GraphType* g, int v)
{
	GraphNode* w;
	QueueType q;

	queue_init(&q);    		// ť �ʱ� ȭ 
	visited[v] = TRUE;      // ���� v �湮 ǥ�� 
	printf("%d �湮 -> ", v);
	enqueue(&q, v);			// ���������� ť�� ���� 
	while (!is_empty(&q)) {
		v = dequeue(&q);		// ť�� ����� ���� ���� 
		for (w = g->adj_list[v]; w; w = w->link) //���� ���� Ž��
			if (!visited[w->vertex]) {	// �̹湮 ���� Ž�� 
				visited[w->vertex] = TRUE;   // �湮 ǥ��
				printf("%d �湮 -> ", w->vertex);
				enqueue(&q, w->vertex);	//������ ť�� ����
			}
	}
}
int main(void)
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	graph_init(g);
	for (int i = 0; i < 6; i++)
		insert_vertex(g);
	insert_edge(g, 0, 2);
	insert_edge(g, 2, 1);
	insert_edge(g, 2, 3);
	insert_edge(g, 0, 4);
	insert_edge(g, 4, 5);
	insert_edge(g, 1, 5);

	printf("�ʺ� �켱 Ž��\n");
	bfs_list(g, 0);
	printf("\n");
	free(g);
	return 0;
}