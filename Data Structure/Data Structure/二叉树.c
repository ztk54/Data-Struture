#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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
        printf("%c  ", root->data);
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
    PrintTree(bt->LChild, nLayer + 1);
    for (int i = 0; i < nLayer; i++)
        printf("   ");
    printf("%c\n", bt->data);
    PrintTree(bt->RChild, nLayer + 1);
}

int main()
{
    BiTree T;
    int layer = 0;
    printf("按扩展先序遍历序列建立二叉树，请输入序列:\n");
    CreateBiTree(&T);
    printf("先序遍历输出序列为:");
    PreOrder(T);
    printf("\n中序遍历输出序列为:");
    InOrder(T);
    printf("\n后序遍历输出序列为:");
    PostOrder(T);
    printf("\n按竖向树状打印二叉树:\n");
    PrintTree(T, layer);
    return 0;
}