#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
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

//递归销毁二叉树
void BinaryTreeDestory(BTNode** root);

//递归得到二叉树节点个数
int BinaryTreeSize(BTNode* root);

//递归得到二叉树叶子节点个数，叶子节点是指左右子数都为空的二叉树
int BinaryTreeLeafSize(BTNode* root);

//递归得到第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k);

//递归得到层数
int BinaryTreeDepth(BTNode* root);

//递归查找对应节点x
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

// 二叉树前序遍历 根左右
void BinaryTreePrevOrder(BTNode* root);

// 二叉树中序遍历  左根右
void BinaryTreeInOrder(BTNode* root);

// 二叉树后序遍历  左右根
void BinaryTreePostOrder(BTNode* root);

// 层序遍历  使用queue数据结构来进行
void BinaryTreeLevelOrder(BTNode* root);

// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);

//根据前序和中序遍历得到原二叉树
BTNode* build_pre_in(BTDataType pre[], BTDataType in[], int pre_start, int in_start, int size);

//如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
bool isUnivalTree(BTNode* root);

//给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
bool isSameTree(BTNode* p, BTNode* q);