#include <iostream>
#include <queue>
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
// 检查是否是完全二叉树
bool checkCompeleteTree(BiTNode *head)
{
    // 基于层序遍历的原理
    queue<BiTNode *> queue;
    // 判断当前是否遇到过n-1层的叶子节点
    bool leaf = false;
    // 判断左右孩子是否存在的临时节点
    BiTNode *lchild = NULL;
    BiTNode *rchild = NULL;
    // 临时变量 存储queue弹出元素
    BiTNode *cur = NULL;
    // 将头节点压入栈中
    queue.push(head);
    while (!queue.empty())
    {
        cur = queue.front();
        queue.pop();
        lchild = cur->lchild;
        rchild = cur->rchild;

        //出现
        //1.任意节点有右节点无左节点
        // 2.在leaf激活的情况下 遇到子树尚存的情况
        if ((leaf && (lchild != NULL || rchild != NULL) || (lchild == NULL && rchild != NULL)))
        {
            return false;
        }

        // 如果左右孩子尚全 则左右孩子入栈
        if (lchild != NULL)
        {
            queue.push(lchild);
        }
        if (rchild != NULL)
        {
            queue.push(rchild);
        }
        // 当出现左右子不全的情况 激活leaf属性
        if (rchild == NULL || lchild == NULL)
        {
            leaf = true;
        }
    }
    return true;
}
int main()
{
    BiTNode *head = new BiTNode('A');
    head->lchild = new BiTNode('B');
    // 测试不是完全二叉树数据
    head->lchild->rchild = new BiTNode('D');
    head->rchild = new BiTNode('C');
    if (checkCompeleteTree(head))
    {
        cout << "是完全二叉树" << endl;
    }
    else
    {
        cout << "不是完全二叉树" << endl;
    }
}
// BiTNode *Create_BiTree()
// {
//     // 创建结构体
//     BiTNode *T = new BiTNode;
//     ElemType ch;
//     cin >> ch;
//     if (ch == '#')
//     {
//         return;
//     }
//     else
//     {
//         T->data = ch;
//         T->lchild = Create_BiTree();
//         T->rchild = Create_BiTree();
//     }
//     return T;
// }