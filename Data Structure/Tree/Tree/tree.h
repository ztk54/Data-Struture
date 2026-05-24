#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
//pi是得到的节点个数，在主函数中设置pi=0，然后以指针的形式传入函数（保证改变影响本身）
BTNode* BinaryTreeCreate(BTDataType* a, int* pi);

BTNode* BuyNode(BTDataType x);

//递归得到二叉树节点个数
int BinaryTreeSize(BTNode* root);

//递归得到二叉树叶子节点个数，叶子节点是指左右子数都为空的二叉树
int BinaryTreeLeafSize(BTNode* root);


int BinaryTreeLevelKSize(BTNode* root, int k);



