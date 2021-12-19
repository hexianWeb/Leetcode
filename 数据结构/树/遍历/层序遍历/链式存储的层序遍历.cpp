#include <stdlib.h> //注意 malloc和free的函数都在stdlib里 注意引入
#include <stdio.h>
#include <iostream>
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

// 初始化
void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    //空表初始指向空
    Q.rear->next = NULL;
}
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
        head->data = value;
        Pre_CreateBiTree(head->lchild);
        Pre_CreateBiTree(head->rchild);
    }
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
        cout << p->data << ",";
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
int main()
{
    BiTree T;
    cout << "请输入元素 构建二叉树" << endl;
    Pre_CreateBiTree(T);
    LevelOrder(T);
    return 0;
}