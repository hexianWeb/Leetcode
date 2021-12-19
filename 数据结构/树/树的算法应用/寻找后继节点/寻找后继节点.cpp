#include <iostream>

using namespace std;

typedef char Elemtype;

// 定义二叉树结构体
class BiTNode
{
public:
    Elemtype data;
    BiTNode *lchild;
    BiTNode *rchild;
    BiTNode *parent;
    BiTNode(Elemtype x)
    {
        this->data = x;
        this->lchild = NULL;
        this->rchild = NULL;
        this->parent = NULL;
    }
};
// 寻找最左节点的函数
BiTNode *getLeftMost(BiTNode *node)
{
    if (node->lchild != NULL)
    {
        node = node->lchild;
        getLeftMost(node);
    }
    return node;
}
// X存在右树 X的后继是右子树 最左节点

// X没有右树 则向上寻找 找到视当前子树为左子树的父节点

BiTNode *getSuccessorNode(BiTNode *node)
{
    if (node == NULL)
    {
        return node;
    }

    if (node->rchild != NULL)
    {
        return getLeftMost(node->rchild);
    }
    else
    {
        BiTNode *Parent = node->parent;
        BiTNode *cur = node;
        while (Parent->lchild != cur && Parent != NULL)
        {
            cur = Parent;
            Parent = Parent->parent;
        }
        return Parent;
    }
}
int main()
{
    BiTNode *head = new BiTNode('A');
    BiTNode *o1 = new BiTNode('B');
    BiTNode *o2 = new BiTNode('C');
    BiTNode *o3 = new BiTNode('D');
    head->lchild = o1;
    o1->lchild = o2;
    o1->rchild = o3;
    o1->parent = head;
    o2->parent = o1;
    o3->parent = o1;
    // cout << getLeftMost(head)->data;
    cout << "寻找D节点的直接后继 结果展示：" << getSuccessorNode(o3)->data << endl;
}