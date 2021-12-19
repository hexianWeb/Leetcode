#include <stdlib.h> //注意 malloc和free的函数都在stdlib里 注意引入
#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
// 二叉树结构体
typedef struct BiTNode
{
    /* data */
    char data;
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

// 初始化
void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    //空表初始指向空
    Q.rear->next = NULL;
}
// 判断空操作
bool IsEmpty(LinkQueue Q)
{
    if (Q.front == Q.rear)
    {
        /* code */
        return true;
    }
    return false;
}
bool EnQueue(LinkQueue &Q, BiTNode *temp_node)
{
    LinkNode *temp = (LinkNode *)malloc(sizeof(LinkNode));
    if (temp == NULL)
    {
        /* code */
        return false;
    }
    temp->data = temp_node;
    temp->next = NULL;
    Q.rear->next = temp;
    Q.rear = temp;
    return true;
}
bool DeQueue(LinkQueue &Q, BiTNode *temp_Denode)
{
    if (Q.front == Q.rear)
    {
        /* code */
        printf("此队列为NULL");
    }
    LinkNode *temp = Q.front->next;
    temp_Denode = temp->data;
    Q.front->next = temp->next;
    if (Q.rear == temp)
    {
        /* code */
        Q.front = Q.rear;
    }
    free(temp);
    return true;
}
// 层序遍历核心代码实现
void LevelOrder(BiTree T)
{
    LinkQueue Q;
    // 初始化辅助队列
    InitQueue(Q);
    BiTree p;
    EnQueue(Q, T);
    while (!IsEmpty(Q))
    {
        DeQueue(Q, p);
        printf("%s", p->data);
        if (p->lchild != NULL)
        {
            EnQueue(Q, p->lchild);
        }
        else if (p->rchild != NULL)
        {
            /* code */
            EnQueue(Q, p->rchild);
        }
    }
}
// thinking： 如果任意一个节点有右孩子 没有左孩子 则为false 如果在1为 true的情况下遇到一个左右孩子不全的节点，则后续节点需要全为叶子节点
// 判断是否是二叉树的核心代码
bool checkCompeleteTree(BiTree T)
{
    queue<BiTree> queue;
    // leaf :是否遇到过一个左右子不全的情况
    bool leaf = false;
    BiTree left = NULL;
    BiTree right = NULL;
    queue.push(T);
    while (!queue.empty())
    {
        T = queue.front();
        queue.pop();
        left = T->lchild;
        right = T->rchild;
        if ((leaf && (left != NULL || right != NULL) || (left == NULL && right != NULL)))
        {
            return false;
        }

        if (left != NULL)
        {
            queue.push(left);
        }
        if (right != NULL)
        {
            queue.push(right);
        }
        // 出现少子情况 后序节点全为叶子节点
        if (right == NULL || left == NULL)
        {
            leaf = true;
        }
    }
}
int main()
{

    return 0;
}