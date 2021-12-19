#include <stdlib.h> //注意 malloc和free的函数都在stdlib里 注意引入
#include <stdio.h>
#include <iostream>
// 结构体定义  初始Elemtype为int
typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;

} BiTNode, *BiTree;
// 初始化二叉树根节点
void InitBiTree(BiTree *root)
{
    *root = nullptr;
    (*root)->lchild = nullptr;
    (*root)->rchild = nullptr;
}
// 先序遍历创建二叉树
void Pro_CreateBiTree(BiTree &T)
{
    char value;
    scanf("%c", &value);
    if (value == '#')
    {
        /* code */
        T = NULL;
    }
    else
    {
        T = (BiTree)malloc(sizeof(BiTNode));
        // 当前父亲节点赋值
        T->data = value;
        Pro_CreateBiTree(T->lchild);
        Pro_CreateBiTree(T->rchild);
    }
}
// 输出节点 操作节点函数
void visit(BiTree T)
{
    if (T->data != '#')
    {
        /* code */
        printf("二叉树元素有%c\n", T->data);
    }
}
// 先序遍历查看二叉树
void GetElemsBiTree(BiTree T)
{
    if (T != NULL)
    {
        visit(T);
        GetElemsBiTree(T->lchild);
        GetElemsBiTree(T->rchild);
    }
}

// 主题函数
int main()
{
    BiTree T;
    // InitBiTree(T);
    // 插入新节点
    Pro_CreateBiTree(T);
    GetElemsBiTree(T);
    return 0;
}