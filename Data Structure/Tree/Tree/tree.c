#include "tree.h"

BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}
	//封装一个函数为二叉树动态申请节点
	BTNode* root = BuyNode(a[*pi]);
	(*pi)++;
	root->left = BinaryTreeCreate(a, pi);
	root->right = BinaryTreeCreate(a, pi);
	return root;
}

BTNode* BuyNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("Malloc Failed!");
		exit(1);
	}
	newnode->data = x;
	newnode->left = newnode->right = NULL;
	return newnode;
}

int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
	return 0;
}

int BinaryTreeLeafSize(BTNode* root)
{
	//这里依旧要检查root为空的情况，否则可能会对NULL发生解引用现象
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

