#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

// 定义数据类型以及结构体
typedef char ElemType;
// 定义返回对象的结构体以及构造函数
// 定义二叉树的结构体
class BiTNode
{
public:
    ElemType data;
    BiTNode *lchild;
    BiTNode *rchild;
    BiTNode(ElemType x)
    {
        this->data = x;
        this->lchild = NULL;
        this->rchild = NULL;
    }
};

class Info
{
public:
    int height;
    int nodes;
    Info(int h, int n)
    {
        this->height = h;
        this->nodes = n;
    }
};

Info process(BiTNode *x)
{
    // 情况 树空
    if (x == NULL)
    {
        return Info(0, 0);
    }
    // 左子树 右子树 结果反馈
    Info leftData = process(x->lchild);
    Info rightData = process(x->rchild);
    int height = max(leftData.height, rightData.height);
    int nodes = leftData.nodes + rightData.nodes + 1;
    return Info(height, nodes);
}

bool ISF(BiTNode *head)
{
    if (head == NULL)
    {
        return true;
    }
    // 根节点获取左右子树节点总数 以及总高度
    Info data = process(head);
    // 公式 节点总数 等于 2的高度次方-1
    // 位运算 右移动h位 即为2的h次方
    return data.nodes == (1 << data.height - 1);
}