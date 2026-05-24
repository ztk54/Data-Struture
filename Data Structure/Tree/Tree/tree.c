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

void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
	{
		return;
	}
	BinaryTreeDestory(&(*root)->left);
	BinaryTreeDestory(&(*root)->right);
	free(*root);
	*root = NULL;
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

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	//注意这里两个if判断不能更改顺序，否则NULL也被当为了有效节点
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->left, k - 1)
		+ BinaryTreeLevelKSize(root->right, k - 1);
}

int BinaryTreeDepth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int left = BinaryTreeDepth(root->left);
	int right = BinaryTreeDepth(root->right);
	return 1 + (left > right ? left : right);
	return 0;
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == x)
	{
		return root;
	}
	BTNode* left = BinaryTreeFind(root->left, x);
	if (left)
	{
		return left;
	}
	BTNode* right = BinaryTreeFind(root->right, x);
	if (right)
	{
		return right;
	}
}

void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL");
		return;
	}
	printf("%c ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}

void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL");
		return;
	}
	BinaryTreeInOrder(root->left);
	printf("%c ", root->data);
	BinaryTreeInOrder(root->right);
}

void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL");
		return;
	}
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->data);
}

