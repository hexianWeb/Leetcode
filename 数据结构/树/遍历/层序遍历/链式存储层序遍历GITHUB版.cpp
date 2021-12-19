#include <stdlib.h> //注意 malloc和free的函数都在stdlib里 注意引入
#include <stdio.h>
#include <iostream>
#include <queue>         //引入队列头文件
#include <unordered_map> //引入带有键与值的map头文件
using namespace std;

// 定义elemtype结构体
typedef char ElemType;
// 二叉树结构体
typedef struct BiTNode
{
    /* data */
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
// 队列节点结构体
typedef struct LinkNode
{
    // 存储数据结构更改为二叉树节点
    BiTNode *data;
    struct LinkNode *next;
} LinkNode;
// 队列 头尾指针结构体
typedef struct
{
    /* data */
    LinkNode *front, *rear;
} LinkQueue;

// 创建二叉树
void Pre_CreateBiTree(BiTree &head)
{
    ElemType value;
    cin >> value;
    if (value == '#')
    {
        head = NULL;
    }
    else
    {
        head = (BiTNode *)malloc(sizeof(BiTNode));
        head->data = value;
        Pre_CreateBiTree(head->lchild);
        Pre_CreateBiTree(head->rchild);
    }
}
// 一个普通的visit函数
void visit(BiTNode *node)
{
    if (node->data != '#')
    {
        cout << node->data << ",";
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
//层序遍历
void LevelOrderTraversal(BiTNode *T)
{
    queue<BiTNode *> queue;
    BiTNode *cur = T;
    // 头节点入栈
    queue.push(cur);
    while (!queue.empty())
    {
        cur = queue.front();
        queue.pop();
        cout << cur->data << ",";
        // 左孩子存在 则左孩子入队列
        if (cur->lchild != NULL)
        {
            queue.push(cur->lchild);
        }
        // 右孩子相同 右孩子进入队列
        if (cur->rchild != NULL)
        {
            queue.push(cur->rchild);
        }
    }
}
int main()
{
    BiTree T;
    cout << "建立二叉树：" << endl;
    Pre_CreateBiTree(T);
    cout << "建立完毕" << endl;
    cout << "层序遍历开始：" << endl;
    LevelOrderTraversal(T);
}