#include <stdlib.h>
#include <stdio.h>

// 定义结构体
typedef struct BTSNode
{
    /* data */
    int data;
    struct BTSNode *lchild, *rchild;
} BTSNode, *BTSTree;

// // 非递归实现二叉排序树查找
// BTSNode *BTS_Search(BTSTree T, int key)
// {
//     while (T != NULL && T->data != key)
//     {
//         /* code */
//         if (T->data > key)
//         {
//             /* code */
//             T = T->rchild;
//         }
//         else
//         {
//             T = T->lchild;
//         }
//     }
// }
//递归实现二叉排序树查找
BTSNode *BTSSreach(BTSTree T, int key)
{
    if (T == NULL)
    {
        /* code */
        printf("查找失败");
        return NULL;
    }
    if (T->data > key)
    {
        /* code */
        return BTSSreach(T->rchild, key);
    }
    else
    {
        /* code */
        return BTSSreach(T->lchild, key);
    }
}

// 插入操作实现 递归操作实现 最坏空间复杂度O（h）
bool BST_Insert(BTSTree &T, int key)
{
    if (T == NULL)
    {
        T = (BTSNode *)malloc(sizeof(BTSNode));
        T->data = key;
        T->lchild = NULL;
        T->rchild = NULL;
        return true;
    }
    // 排序树中有相同元素
    else if (key == T->data)
    {
        /* code */
        return false;
    }
    else if (key >= T->data)
    {
        /* code */
        return BST_Insert(T->rchild, key);
    }
    else
    {
        return BST_Insert(T->lchild, key);
    }
}
// 非递归操作实现 常量级空间复杂度
bool BTSInsert(BTSTree &T, int key)
{
    while (T != NULL)
    {
        /* code */
        if (key == T->data)
        {
            /* code */
            return false;
        }
        else if (key >= T->data)
        {
            /* code */
            T = T->rchild;
        }
        else
        {
            T = T->lchild;
        }
    }
    T = (BTSNode *)malloc(sizeof(BTSNode));
    T->data = key;
    T->lchild = NULL;
    T->rchild = NULL;
    return true;
}

// 构造二叉排序树
bool Create_BTS(BTSTree &T, int str[], int n)
{
    T = NULL;
    int i = 0;
    while (i < n)
    {
        /* code */
        BST_Insert(T, str[i]);
        i++;
    }
}