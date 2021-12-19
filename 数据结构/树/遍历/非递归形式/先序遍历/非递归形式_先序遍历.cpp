#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <iostream>
using namespace std;
// / 定义ELEMTYPE类型
typedef char Elemtype;

// 二叉树结构体
typedef struct BiTNode
{
    Elemtype data;
    struct BiTNode *left, *right;
} BiTNode, *BiTree;

// 初始化 二叉树根节点
bool InitBiTree(BiTree &root)
{
    root = (BiTNode *)malloc(sizeof(BiTNode));
    if (root == NULL)
    {
        return false;
    }
    root->data = '#';
    root->left = NULL;
    root->right = NULL;
    return true;
}

// 一个普通的visit函数
void visit(BiTNode *node)
{
    if (node->data != '#')
    {
        cout << node->data << ",";
    }
}

bool Pre_CreatBiTree(BiTree &T)
{
    Elemtype value;
    cin >> value;
    if (value == '#')
    {
        T = NULL;
    }
    else
    {
        T = (BiTree)malloc(sizeof(BiTNode));
        if (!T)
        {
            cout << "节点内存分配失败" << endl;
            return false;
        }
        T->data = value;
        Pre_CreatBiTree(T->left);
        Pre_CreatBiTree(T->right);
    }
    return true;
}
// void PreOrderUnRecur(BiTree head)
// {
//     stack<BiTree> s;
//     BiTree p = head;
//     cout << "先序遍历结果" << endl;
//     // s.push(p);
//     while (p != NULL || !s.empty())
//     {
//         p = s.top();
//         s.pop();
//         visit(p);
//         if (p->right != NULL)
//         {
//             s.push(p->right);
//         }
//         if (p->left != NULL)
//         {
//             s.push(p->left);
//         }
//     }
// }
// 先序遍历
void PreOrder2(BiTNode *root)
{
    stack<BiTNode *> s;
    BiTNode *p = root;
    while (p != NULL || !s.empty())
    {
        while (p != NULL)
        {
            visit(p);
            s.push(p);
            p = p->left;
        }
        if (!s.empty())
        {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
}
// 先序遍历查看二叉树
void GetElemsBiTree(BiTree T)
{
    if (T != NULL)
    {
        visit(T);
        GetElemsBiTree(T->left);
        GetElemsBiTree(T->right);
    }
}
int main()
{
    BiTree T;
    Pre_CreatBiTree(T);
    // 递归遍历测试
    // GetElemsBiTree(T);
    // 非递归遍历测试
    PreOrder2(T);
    return 0;
}
// 构建一个栈
// 每次
//      从栈中弹出一个节点cur
//      处理当前节点cur
//      将子节点压入栈中 先右再左
//      重复步骤3 直到栈空
