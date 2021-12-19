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
// 返回结果为当前子树是否为平衡树 以及当前子树的高度
class ReturnType
{
public:
    bool isBalanced;
    int height;
    ReturnType(bool isB, int hei)
    {
        this->isBalanced = isB;
        this->height = hei;
    }
};

//
ReturnType process(BiTNode *x)
{
    // 当树为空时
    if (x == NULL)
    {
        return ReturnType(true, 0);
    }
    // 返回左右子树是否是平衡二叉树 以及最大高度
    ReturnType leftData = process(x->lchild);
    ReturnType rightData = process(x->rchild);
    // 当前树的高度为左右子树的最大高度+1
    int height = max(leftData.height, rightData.height) + 1;
    // 判断是否为平衡二叉树 子树高度差小于2 且都为平衡二叉树
    bool isBalanced = leftData.isBalanced && rightData.isBalanced && abs(leftData.height - rightData.height) < 2;
    //返还结果
    return ReturnType(isBalanced, height);
}
// 核心函数
bool IsBalanced(BiTNode *head)
{
    return process(head).isBalanced;
}