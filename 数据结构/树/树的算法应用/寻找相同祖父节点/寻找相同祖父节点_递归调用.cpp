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
    BiTNode(Elemtype x)
    {
        this->data = x;
        this->lchild = NULL;
        this->rchild = NULL;
    }
};

// thiking :类似于寻得目标节点向上传递
//  递归逻辑
// 向下递归寻找的时候有二种情况
// 1.当前节点为空 则无节点向上传递
// 2.寻找到目标节点 o1或o2 则 目标节点向上传递

// 算法逻辑
// 两种情况
// 情况一：
// o1是o2或o2是o1的祖先节点
// 情况二：
// o1与o2不在同一条子树上
BiTNode *lowestAncestor(BiTNode *head, BiTNode *o1, BiTNode *o2)
{
    if (head == NULL || head == o1 || head == o2)
    {
        return head;
    }
    BiTNode *left = lowestAncestor(head->lchild, o1, o2);
    BiTNode *right = lowestAncestor(head->rchild, o1, o2);
    if (left != NULL && right != NULL)
    {
        return head;
    }
    return left != NULL ? left : right;
}

int main()
{
    BiTNode *head = new BiTNode('A');
    BiTNode *o1 = new BiTNode('B');
    BiTNode *o2 = new BiTNode('C');
    head->lchild = o1;
    // head->rchild = o2;
    o1->lchild = o2;
    BiTNode *temp = lowestAncestor(head, o1, o2);
    cout << "寻找祖父节点结果展示:" << endl;
    cout << temp->data << endl;
    ;
    return 0;
}