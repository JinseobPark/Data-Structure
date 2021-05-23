/****************************************************
\file   tree_find_smaller.c
\author Jinseob Park
\par    email: 0814owl@gmail.com
\brief	트리에서 주어진 값보다 작은 노드를 구하는 프로그램
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

/**************************************************
root : root of tree
value : comparing with node
***************************************************/
void print_less(TreeNode* root, element value)
{
	if (root) {
		print_less(root->left, value);// 왼쪽서브트리 순회
		if(root->key < value)
		printf("%d보다 작은 노드 : %d \n ", value, root->key);  // 노드 방문
		print_less(root->right, value);// 오른쪽서브트리 순회
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