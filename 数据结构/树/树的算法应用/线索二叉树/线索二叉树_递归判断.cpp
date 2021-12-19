#include <iostream>

using namespace std;

typedef int ElemType;

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
static int PreValue = INT8_MIN;
// THINKING : 基于中序遍历解决是否为搜素二叉树
// 搜素二叉树一定是左子树小于根小于右子树
bool checkIsBalanceSearchTree(BiTNode *head)
{
    if (head == nullptr)
    {
        return true;
    }
    // 判断左子树 是否满足线索二叉树的特征
    bool isLeftBST = checkIsBalanceSearchTree(head->lchild);
    // 先检查左树与根树 再检查右子树 左根 右
    if (head->data <= PreValue)
    {
        return false;
    }
    else
    {
        PreValue = head->data;
    }
    return checkIsBalanceSearchTree(head->rchild);
}
int main()
{
    BiTNode *head = new BiTNode(2);
    head->lchild = new BiTNode(1);
    head->lchild->lchild = new BiTNode(4);
    head->rchild = new BiTNode(3);
    if (checkIsBalanceSearchTree(head))
    {
        cout << "该树为线索二叉树" << endl;
    }
    else
    {
        cout << "该树不是线索二叉树" << endl;
    }
    return 0;
}