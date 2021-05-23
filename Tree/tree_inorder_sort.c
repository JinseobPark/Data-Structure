/****************************************************
\file   tree_inorder_sort.c
\author Jinseob Park
\par    email: 0814owl@gmail.com
\brief	Ʈ���� ���� ��ȸ�� �����ϴ� ���α׷�
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
	// Ʈ���� �����̸� ���ο� ��带 ��ȯ�Ѵ�. 
	if (node == NULL) return new_node(key);

	// �׷��� ������ ��ȯ������ Ʈ���� ��������. 
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);

	// ����� ��Ʈ �����͸� ��ȯ�Ѵ�. 
	return node;
}

// ���� ��ȸ
void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);// ���ʼ���Ʈ�� ��ȸ
		printf("[%d] ", root->key);  // ��� �湮
		inorder(root->right);// �����ʼ���Ʈ�� ��ȸ
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