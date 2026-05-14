#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

typedef char DataType;
typedef struct Node 
{
    DataType data;
    struct Node* LChild;
    struct Node* RChild;
} BiTNode, * BiTree;

void CreateBiTree(BiTree* bt) 
{
    char ch;
    ch = getchar();
    if (ch == '#')
        *bt = NULL;
    else 
    {
        *bt = (BiTree)malloc(sizeof(BiTNode));
        (*bt)->data = ch;
        CreateBiTree(&((*bt)->LChild));
        CreateBiTree(&((*bt)->RChild));
    }
}

void PreOrder(BiTree root) 
{
    if (root != NULL) 
    {
        printf("%c", root->data);
        PreOrder(root->LChild);
        PreOrder(root->RChild);
    }
}

void InOrder(BiTree root) 
{
    if (root != NULL) 
    {
        InOrder(root->LChild);
        printf("%c", root->data);
        InOrder(root->RChild);
    }
}

void PostOrder(BiTree root) 
{
    if (root != NULL)
    {
        PostOrder(root->LChild);
        PostOrder(root->RChild);
        printf("%c", root->data);
    }
}

void PrintTree(BiTree bt, int nLayer)
{
    if (bt == NULL) return;
    PrintTree(bt->RChild, nLayer + 1);
    for (int i = 0; i < nLayer; i++)
        printf("   ");
    printf("%c\n", bt->data);
    PrintTree(bt->LChild, nLayer + 1);
}

int CountNodes(BiTree root) 
{
    if (root == NULL) return 0;
    return 1 + CountNodes(root->LChild) + CountNodes(root->RChild);
}

int CountLeaf(BiTree root) 
{
    if (root == NULL) return 0;
    if (root->LChild == NULL && root->RChild == NULL)
        return 1;
    return CountLeaf(root->LChild) + CountLeaf(root->RChild);
}

int TreeDepth(BiTree root) 
{
    if (root == NULL) return 0;
    int left = TreeDepth(root->LChild);
    int right = TreeDepth(root->RChild);
    return (left > right ? left : right) + 1;
}

/* ================= 层次遍历 ================= */
#define MAXSIZE 100

typedef struct 
{
    BiTree data[MAXSIZE];
    int front;
    int rear;
} Queue;

void InitQueue(Queue* Q) 
{
    Q->front = Q->rear = 0;
}

int IsEmpty(Queue* Q)
{
    return Q->front == Q->rear;
}

void EnQueue(Queue* Q, BiTree x) 
{
    if ((Q->rear + 1) % MAXSIZE == Q->front)
        return;
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MAXSIZE;
}

BiTree DeQueue(Queue* Q) 
{
    BiTree x = NULL;
    if (!IsEmpty(Q)) 
    {
        x = Q->data[Q->front];
        Q->front = (Q->front + 1) % MAXSIZE;
    }
    return x;
}

void LevelOrder(BiTree root) 
{
    Queue Q;
    BiTree p;
    InitQueue(&Q);

    if (root != NULL)
        EnQueue(&Q, root);

    while (!IsEmpty(&Q)) 
    {
        p = DeQueue(&Q);
        printf("%c ", p->data);

        if (p->LChild != NULL)
            EnQueue(&Q, p->LChild);
        if (p->RChild != NULL)
            EnQueue(&Q, p->RChild);
    }
}

/* ================= 非递归中序遍历 ================= */
#define STACKSIZE 100

typedef struct 
{
    BiTree data[STACKSIZE];
    int top;
} Stack;

void InitStack(Stack* S) 
{
    S->top = -1;
}

int StackEmpty(Stack* S)
{
    return S->top == -1;
}

void Push(Stack* S, BiTree x) 
{
    if (S->top < STACKSIZE - 1)
        S->data[++S->top] = x;
}

BiTree Pop(Stack* S) 
{
    if (!StackEmpty(S))
        return S->data[S->top--];
    return NULL;
}

void InOrder_NonRec(BiTree root)
{
    Stack S;
    BiTree p = root;
    InitStack(&S);

    while (p != NULL || !StackEmpty(&S)) 
    {
        if (p != NULL) 
        {
            Push(&S, p);
            p = p->LChild;
        }
        else 
        {
            p = Pop(&S);
            printf("%c ", p->data);
            p = p->RChild;
        }
    }
}

/* ================= 非递归后序遍历 ================= */
void PostOrder_NonRec(BiTree root) 
{
    Stack S1, S2;
    BiTree p = root;
    InitStack(&S1);
    InitStack(&S2);

    if (p != NULL)
        Push(&S1, p);

    while (!StackEmpty(&S1)) 
    {
        p = Pop(&S1);
        Push(&S2, p);

        if (p->LChild != NULL)
            Push(&S1, p->LChild);
        if (p->RChild != NULL)
            Push(&S1, p->RChild);
    }

    while (!StackEmpty(&S2)) 
    {
        p = Pop(&S2);
        printf("%c ", p->data);
    }
}




int main() 
{
    BiTree T;
    int layer = 0;
    printf("按扩展先序遍历序列建立二叉树，请输入序列:\n");
    CreateBiTree(&T);

    //printf("先序遍历输出序列为：");
    //PreOrder(T);
    //printf("\n中序遍历输出序列为");
    //InOrder(T);
    //printf("\n后序遍历输出序列为:");
    //PostOrder(T);

    //printf("\n按竖向树状打印二叉树:\n");
    //PrintTree(T, layer);
    //printf("结点总数为：%d\n", CountNodes(T));
    //printf("叶子结点数为：%d\n", CountLeaf(T));
    //printf("二叉树高度为：%d\n", TreeDepth(T));

    printf("\n层次遍历输出序列为：");
    LevelOrder(T);

    printf("\n非递归中序遍历：");
    InOrder_NonRec(T);

    printf("\n非递归后序遍历：");
    PostOrder_NonRec(T);


    return 0;
}

