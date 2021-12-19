#include <stack>
#include <iostream>
using namespace std;

typedef char ElemType;
//二叉树结构体
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 一个visit函数
void visit(BiTNode *node)
{
    cout << node->data << ",";
}

void In_CreatBiTree(BiTree &T)
{
    ElemType value;
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
            cout << "FALSE！！" << endl;
        }
        In_CreatBiTree(T->lchild);
        T->data = value;
        In_CreatBiTree(T->rchild);
    }
}
void inOrderUnRecur(BiTree head)
{
    cout << "中序遍历的结果:" << endl;
    if (head != NULL)
    {
        stack<BiTree> stack;
        while (!stack.empty() || head != NULL)
        {
            if (head != NULL)
            {
                stack.push(head);
                head = head->lchild;
            }
            else
            {
                head = stack.top();
                stack.pop();
                visit(head);
                head = head->rchild;
            }
        }
    }
}

void GetELemsBiTree(BiTree T)
{
    if (T != NULL)
    {
        GetELemsBiTree(T->lchild);
        visit(T);
        GetELemsBiTree(T->rchild);
    }
}
// 中序遍历 改版
void InOrder(BiTNode *head)
{
    cout << "中序遍历开始:" << endl;
    stack<BiTNode *> stack;
    BiTNode *p = head;
    if (head != NULL)
    {
        while (p != NULL || !stack.empty())
        {
            // 一直遍历到最左子树节点
            if (p != NULL)
            {
                stack.push(p);
                p = p->lchild;
            }
            // 挨个向上判断是否有右兄弟接待
            else
            {
                p = stack.top();
                stack.pop();
                visit(p);
                p = p->rchild;
            }
        }
    }
}

int main()
{
    BiTree T;
    In_CreatBiTree(T);
    cout << "递归中序遍历开始" << endl;
    GetELemsBiTree(T);
    cout << "递归中序遍历结束" << endl;

    cout << "非递归中序遍历开始" << endl;
    InOrder(T);
    cout << "非递归中序遍历结束" << endl;
}

// 整棵树左边界进栈
// 依次弹的过程中 弹出的过程中打印
// 对弹出的节点的右子树周而复始