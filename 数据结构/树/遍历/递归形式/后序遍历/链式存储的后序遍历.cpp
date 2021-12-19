#include <stdlib.h> //注意 malloc和free的函数都在stdlib里 注意引入
#include <stdio.h>
#include <iostream>
using namespace std;
// 定义ELEMTYPE 类型为 char类型
typedef char ElemType;
// 定义二叉树的结构体
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
// 初始化二叉树根节点
bool InitBiTree(BiTree &root)
{
    root = (BiTNode *)malloc(sizeof(BiTNode));
    root->data = '#';
    root->lchild = NULL;
    root->rchild = NULL;
    return true;
}

void visit(BiTree T)
{
    if (T->data = '#')
    {
        cout << T->data << ",";
    }
}
// 后序遍历递归形式创建二叉树
bool Post_CreateBiTree(BiTree &T)
{
    char ch;
    ch = getchar();
    if (ch == '#')
    {
        T == NULL;
    }
    else
    {
        T = (BiTNode *)malloc(sizeof(BiTNode));
        Post_CreateBiTree(T->lchild);
        Post_CreateBiTree(T->rchild);
        T->data = ch;
        return true;
    }
}

void POST_GetElemsBiTree(BiTree T)
{
    if (T->lchild != NULL)
    {
        POST_GetElemsBiTree(T->lchild);
    }
    if (T->rchild != NULL)
    {
        POST_GetElemsBiTree(T->rchild);
    }
    visit(T);
    cout << "完成链式存储递归的后序遍历" << endl;
}

int main()
{
    BiTree T;
    Post_CreateBiTree(T);
    cout << "后序遍历结果输出：" << endl;
    POST_GetElemsBiTree(T);
}