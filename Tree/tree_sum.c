/****************************************************
\file   tree_sum.c
\author Jinseob Park
\par    email: 0814owl@gmail.com
\brief	트리의 노드들의 합을 구하는 프로그램
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

	printf("노드의 합은 %d입니다\n", tree_sum(root));

	return 0;
}