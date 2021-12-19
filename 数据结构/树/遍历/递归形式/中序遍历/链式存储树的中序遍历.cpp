// 字符串类型树结构
#include <stdlib.h> //注意 malloc和free的函数都在stdlib里 注意引入
#include <stdio.h>
#include <iostream>
using namespace std;
// 定义Elemtype 为char类型
typedef char ElemType;
// 定义二叉树结构体
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
// 初始化二叉树根节点
bool InitBiTree(BiTree &root)
{
    root = (BiTNode *)malloc(sizeof(BiTNode)); //为二叉树分配固定节点的内存值
    root->data = '#';
    root->lchild = NULL;
    root->rchild = NULL;
    return true;
}

void visit(BiTree T)
{
    if (T->data != '#')
    {
        cout << T->data << ",";
    }
}
// 中序遍历创建二叉树
void In_CreateBiTree(BiTree &T)
{
    char ch;
    scanf("%c", &ch);
    if (ch == '#')
    {
        T == NULL;
    }
    else /* condition */
    {
        T = (BiTNode *)malloc(sizeof(BiTNode));
        In_CreateBiTree(T->lchild);
        T->data = ch;
        In_CreateBiTree(T->rchild);
    }
}
// 中序遍历查看二叉树
bool IN_GetElemsBiTree(BiTree T)
{
    if (T->lchild != NULL) // 检查节点仍然有左子树 即可以继续向左遍历
    {
        IN_GetElemsBiTree(T->lchild);
    }

    visit(T); //对节点进行操作

    if (T->rchild != NULL)
    {
        /* code */
        IN_GetElemsBiTree(T->rchild);
    }

    return true;
}
int main()
{
    BiTree T;
    In_CreateBiTree(T);
    cout << "链式存储结构中序遍历结果:" << endl;
    IN_GetElemsBiTree(T);
    cout << endl;
    return 0;
}