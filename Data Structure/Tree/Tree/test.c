#include "tree.h"

int main()
{
	char arr[] = "ABD##E#H##CF##G##";
	int pi = 0;
	int size = 0;
	BTNode* root = BinaryTreeCreate(arr, &pi);
	int k = BinaryTreeSize2(root, &size);
	printf("二叉树节点个数为：%d\n",k);
	printf("二叉树节点个数为：%d\n",pi);
	printf("第4层节点个数为：%d\n", BinaryTreeLevelKSize(root, 4));
	printf("叶子节点个数为：%d\n", BinaryTreeLeafSize(root));
	printf("二叉树层数为：%d\n", BinaryTreeDepth(root));
	BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreeInOrder(root);
	printf("\n");
	BinaryTreePostOrder(root);
	printf("\n");
	BinaryTreeLevelOrder(root);
	BinaryTreeDestory(&root);
	return 0;
}

//以下是一道oj题目，根据前序得到二叉树，最后再以中序形式输出
//#include <math.h>
//#include <stdio.h>
//#include <stdlib.h>
//typedef struct BinaryTree
//{
//    char data;
//    struct BinaryTree* left;
//    struct BinaryTree* right;
//}BTNode;
//
//BTNode* creat_node(char x)
//{
//    BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
//    if (newnode == NULL)
//    {
//        exit(0);
//    }
//    newnode->data = x;
//    newnode->left = newnode->right = NULL;
//    return newnode;
//}
//BTNode* build_tree(char* arr, int* pi)
//{
//    if (arr[*pi] == '#')
//    {
//        (*pi)++;
//        return NULL;
//    }
//    BTNode* root = creat_node(arr[*pi]);
//    (*pi)++;
//    root->left = build_tree(arr, pi);
//    root->right = build_tree(arr, pi);
//    return root;
//}
//
//void Inorder(BTNode* root)
//{
//    if (root == NULL)
//    {
//        return;
//    }
//    Inorder(root->left);
//    printf("%c ", root->data);
//    Inorder(root->right);
//}
//
//int main()
//{
//    char arr[100];
//    scanf("%s", arr);
//    int i = 0;
//    BTNode* root = build_tree(arr, &i);
//    Inorder(root);
//}