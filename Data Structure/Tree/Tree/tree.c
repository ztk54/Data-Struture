#include "tree.h"
#include "Queue.h"

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
		printf("NULL ");
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
		printf("NULL ");
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
		printf("NULL ");
		return;
	}
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->data);
}

void BinaryTreeLevelOrder(BTNode* root)
{
	//这里是把BinaryTreeNode*当作元素存储在队列里
	Queue q;
	QueueInit(&q);
	//终于找到问题了，这里我把root->data入队列有点搞笑了，入队列了个char类型常量
	QueuePush(&q, root);
	while (!IsQueueEmpty(&q))
	{
		//取队头，出队头
		BTNode* top = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", top->data);
		//将  队头的  左右孩子入队，刚开始写的是root的左右节点，只能打印一个元素
		if (top->left)
			QueuePush(&q, top->left);
		if (top->right)
			QueuePush(&q, top->right);
	}
	QueueDestroy(&q);
}

int BinaryTreeComplete(BTNode* root)
{
	return 0;
}

BTNode* build_pre_in(BTDataType pre[], BTDataType in[], int pre_start, int in_start, int size)
{
	if (size <= 0)
	{
		return NULL;
	}

	//前序节点就是根节点
	BTDataType root_val = pre[pre_start];
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->data = root_val;
	root->left = root->right = NULL;

	//在中序节点里面找到刚刚那个节点，左边就是左子树，右边是右子树
	int left_size = 0;
	for (int i = 0;i < size;i++)
	{
		if (in[in_start + 1] == root_val)
		{
			left_size = i;
		}
	}
	int right_size = size - left_size - 1;

	//递归左子树
	root->left = build_pre_in(pre, in, pre_start + 1, in_start, left_size);

	//递归右子树
	root->right = build_pre_in(pre, in, pre_start + 1 + left_size, in_start, right_size);
	return root;
}

bool isUnivalTree(BTNode* root)
{
	if (root == NULL)
	{
		return true;
	}
	//root->left是为了防止空指针解引用
	if (root->left && root->left->data != root->data)
	{
		return false;
	}
	if (root->right && root->right->data != root->data)
	{
		return false;
	}
	return isUnivalTree(root->left) && isUnivalTree(root->right);
}

bool isSameTree(BTNode* p, BTNode* q)
{
	//先判断结构是否一样
	if (p == NULL && q == NULL)
	{
		return true;
	}
	if (p == NULL || q == NULL)
	{
		return false;
	}
	//判断内容
	if (p->data != q->data)
	{
		return false;
	}
	//递归左右子树
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}