#include <stack>
#include <iostream>
using namespace std;

// 定义ELEMTYPE类型
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
// 后序遍历**递归形式创建二叉树**
bool Post_CreatBiTree(BiTree &T)
{
    ElemType value;
    // 摄取输入的值
    cin >> value;
    if (value == '#')
    {
        T = NULL;
        return false;
    }
    else
    {
        T = (BiTree)malloc(sizeof(BiTNode));
        Post_CreatBiTree(T->lchild);
        Post_CreatBiTree(T->rchild);
        T->data = value;
    }
    return true;
}

void postOrderUnRecur1(BiTree head)
{
    cout << "后序遍历的结果" << endl;
    if (head != NULL)
    {
        stack<BiTree> stack1;
        stack<BiTree> stack2;
        stack1.push(head);
        while (!stack1.empty())
        {
            head = stack1.top();
            stack2.push(head);
            stack1.pop();
            if (head->lchild != NULL)
            {
                stack1.push(head->lchild);
            }
            if (head->rchild != NULL)
            {
                stack1.push(head->rchild);
            }
        }
        while (!stack2.empty())
        {
            cout << stack2.top() << endl;
            stack2.pop();
        }
    }
}

void POSTOrder(BiTNode *head)
{
    cout << "后序遍历的结果" << endl;
    if (head != NULL)
    {
        stack<BiTNode *> stack1;
        stack<BiTNode *> stack2;
        stack1.push(head);
        while (!stack1.empty())
        {
            head = stack1.top();
            stack2.push(head);
            stack1.pop();
            if (head->lchild != NULL)
            {
                stack1.push(head->lchild);
            }
            if (head->rchild != NULL)
            {
                stack1.push(head->rchild);
            }
        }
        while (!stack2.empty())
        {
            visit(stack2.top());
            stack2.pop();
        }
    }
}
void POST_GetElemsBiTree(BiTree T)
{
    if (T->lchild != NULL)
    {
        POST_GetElemsBiTree(T->lchild);
    }
    if (T->rchild != NULL)
    {
        POST_GetElemsBiTree(T->rchild);
    }
    visit(T);
}

int main()
{
    BiTree T;
    Post_CreatBiTree(T);
    // Pre_CreatBiTree(T);
    cout << "递归调用形式后序遍历结果输出：" << endl;
    POST_GetElemsBiTree(T);
    cout << "完成链式存储递归的后序遍历" << endl;
    cout << "非递归调用形式后序遍历结果输出" << endl;
    POSTOrder(T);
    cout << "非递归形式后序遍历结果输出完毕" << endl;
}