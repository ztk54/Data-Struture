#include "tree.h"

int main()
{
	char arr[] = "ABD##E#H##CF##G##";
	int pi = 0;
	BTNode* root = BinaryTreeCreate(arr, &pi);
	printf("二叉树节点个数为：%d\n",BinaryTreeSize(root));
	printf("二叉树节点个数为：%d\n",pi);
	printf("第4层节点个数为：%d\n", BinaryTreeLevelKSize(root, 4));
	printf("叶子节点个数为：%d\n", BinaryTreeLeafSize(root));
	printf("二叉树层数为：%d\n", BinaryTreeDepth(root));
	//BinaryTreePrevOrder(root);
	//printf("\n");
	//BinaryTreeInOrder(root);
	//printf("\n");
	//BinaryTreePostOrder(root);
	BinaryTreeLevelOrder(root);
	printf("\n");
	BinaryTreeDestory(&root);
	return 0;
}