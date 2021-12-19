#include <stdlib.h> //注意 malloc和free的函数都在stdlib里 注意引入
#include <stdio.h>
#include <iostream>
using namespace std;
// 结构体定义  初始Elemtype为int
typedef int Elemtype;

typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;

} BiTNode, *BiTree;
// 初始化二叉树根节点
bool InitBiTree(BiTree &root)
{
    root = (BiTNode *)malloc(sizeof(BiTNode));
    if (root == NULL)
    {
        /* code */
        return false;
    }
    root->data = 1;
    root->lchild = NULL;
    root->rchild = NULL;
    return true;
}
// 先序遍历创建二叉树
void In_CreateBiTree(BiTree &T)
{
    int value;

    scanf("%d", &value);
    if (value == 9)
    {
        /* code */
        T = NULL;
    }
    else
    {
        T = (BiTNode *)malloc(sizeof(BiTNode));

        // 当前父亲节点赋值
        In_CreateBiTree(T->lchild);
        T->data = value;
        In_CreateBiTree(T->rchild);
    }
}
// 先序遍历查看二叉树
void GetElemsBiTree(BiTree T)
{

    if (T->lchild != NULL)
    {
        /* code */
        GetElemsBiTree(T->lchild);
    }
    printf("二叉树元素有%d\n", T->data);
    if (T->rchild != NULL)
    {
        /* code */
        GetElemsBiTree(T->rchild);
    }
}
// 主题函数
int main()
{
    BiTree T;
    In_CreateBiTree(T);
    GetElemsBiTree(T);
    return 0;
}