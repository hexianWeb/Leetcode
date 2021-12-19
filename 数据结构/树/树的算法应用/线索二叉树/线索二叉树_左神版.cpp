#include <iostream>
#include <queue>
#include <math.h>
#include <algorithm>
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

class ReturnData
{
public:
    bool isBST;
    int min;
    int max;
    ReturnData(bool isB, int min, int max)
    {
        this->isBST = isB;
        this->max = max;
        this->min = min;
    }
};

ReturnData process(BiTNode *x)
{
    if (x == NULL)
    {
        return;
    }
    ReturnData leftData = process(x->lchild);
    ReturnData rightData = process(x->rchild);

    // 获取左子树最小值与最大值
    int min = x->data;
    int max = x->data;
    if (leftData.min != NULL)
    {
        min = std::min(min, leftData.min);
        max = std::max(max, leftData.max);
    }
    // 右子树同理
    if (rightData.min != NULL)
    {
        min = std::min(min, rightData.min);
        max = std::max(max, rightData.max);
    }

    //  判断是否是二叉树 县认定是true 然后看会不会违规
    bool isBST = true;
    // 左树在 左树不是线索树 违规 或者左子树的最大值大于当前节点的值
    if (leftData.isBST != NULL && (!leftData.isBST || leftData.max >= x->data))
    {
        isBST = false;
    }
    // 右树同理
    if (rightData.isBST != NULL && !rightData.isBST || rightData.min <= x->data)
    {
        isBST = false;
    }
}

// 类似原理都是 先判断左右子树是不是 XX类型的树 且当前节点是否满足XX类型的树的规则