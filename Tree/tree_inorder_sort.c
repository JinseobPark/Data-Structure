/****************************************************
\file   tree_inorder_sort.c
\author Jinseob Park
\par    email: 0814owl@gmail.com
\brief	트리를 중위 순회로 정렬하는 프로그램
*****************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode* new_node(int item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
TreeNode* insert_node(TreeNode* node, int key)
{
	// 트리가 공백이면 새로운 노드를 반환한다. 
	if (node == NULL) return new_node(key);

	// 그렇지 않으면 순환적으로 트리를 내려간다. 
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);

	// 변경된 루트 포인터를 반환한다. 
	return node;
}

// 중위 순회
void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);// 왼쪽서브트리 순회
		printf("[%d] ", root->key);  // 노드 방문
		inorder(root->right);// 오른쪽서브트리 순회
	}
}

int main(void)
{
	TreeNode* root = NULL;
	int list[11] = { 11, 3, 4, 1, 56, 5, 6, 2, 98, 32, 23 };
	int i; 
	for (i = 0; i < 11; ++i)
	{
		root = insert_node(root, list[i]);
	}

	inorder(root);
	printf("\n");
	return 0;
}