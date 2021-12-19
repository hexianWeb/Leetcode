#include <stdlib.h> //注意 malloc和free的函数都在stdlib里 注意引入
#include <stdio.h>
// 结构体定义  初始Elemtype为int
typedef struct BiTNode
{
    /* data */
    int data;
    struct BiTNode *lchild, *rchild;

} BiTNode, *BiTree;
// 初始化二叉树根节点
bool InitBiTree(BiTree &root)
{
    root = (BiTree)malloc(sizeof(BiTNode));
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
// 主题函数
int main()
{
    BiTree T;
    if (InitBiTree(T))
    {
        /* code */
        printf("初始化成功!");
    }
    BiTNode *temp = (BiTNode *)malloc(sizeof(BiTNode));
    temp->data = 5;
    temp->lchild = NULL;
    temp->rchild = NULL;
    T->lchild = temp;
    // 插入新节点

    return 0;
}