/****************************************************
\file   tree_sum.c
\author Jinseob Park
\par    email: 0814owl@gmail.com
\brief	Ʈ���� ������ ���� ���ϴ� ���α׷�
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


/************************************
root : root of tree
return : sum of tree nodes
*********************************/
int tree_sum(TreeNode* root) {
	if (root == NULL)
		return 0;
	return root->key + tree_sum(root->left) + tree_sum(root->right);
}

int main(void)
{
	TreeNode* root = NULL;

	root = insert_node(root, 30);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 70);
	root = insert_node(root, 80);
	root = insert_node(root, 60);

	printf("����� ���� %d�Դϴ�\n", tree_sum(root));

	return 0;
}