/****************************************************
\file   tree_find_smaller.c
\author Jinseob Park
\par    email: 0814owl@gmail.com
\brief	Ʈ������ �־��� ������ ���� ��带 ���ϴ� ���α׷�
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

/**************************************************
root : root of tree
value : comparing with node
***************************************************/
void print_less(TreeNode* root, element value)
{
	if (root) {
		print_less(root->left, value);// ���ʼ���Ʈ�� ��ȸ
		if(root->key < value)
		printf("%d���� ���� ��� : %d \n ", value, root->key);  // ��� �湮
		print_less(root->right, value);// �����ʼ���Ʈ�� ��ȸ
	}
}

int main(void)
{
	TreeNode* root = NULL;

	root = insert_node(root, 3);
	root = insert_node(root, 2);
	root = insert_node(root, 10);
	root = insert_node(root, 45);
	root = insert_node(root, 57);
	root = insert_node(root, 66);
	root = insert_node(root, 26);

	print_less(root, 55);
	return 0;
}