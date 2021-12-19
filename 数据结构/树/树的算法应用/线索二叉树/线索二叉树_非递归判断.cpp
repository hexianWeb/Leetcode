#include <iostream>
#include <stack>
using namespace std;

// 定义数据类型以及结构体
typedef char ElemType;
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

// 非递归中序遍历
bool checkIsBalanceSearchTree(BiTNode *head)
{
    // 情况1 树空 平衡
    if (head != NULL)
    {
        stack<BiTNode *> stack;
        BiTNode *p = head;
        static int PreValue = INT16_MIN;
        while (p != NULL || !stack.empty())
        {
            if (p != NULL)
            {
                stack.push(p);
                p = p->lchild;
            }
            else
            {
                p = stack.top();
                stack.pop();
                // 严格升序 左小于根 根小于右
                if (p->data <= PreValue)
                {
                    return false;
                }
                else
                {
                    PreValue = p->data;
                }
                p = p->rchild;
            }
        }
        return true;
    }
    else
    {
        return true;
    }
}
int main()
{
    cout << "判断现在是否是线索二叉树:" << endl;
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
