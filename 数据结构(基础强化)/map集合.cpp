#include <iostream>
#include <unordered_map>
#include <stdio.h>
#include <queue> //引入队列头文件
#include <math.h>
// 命名空间确认
using namespace std;

// 定义elemtype结构体
typedef char ElemType;

// 定义二叉树 结构体
class BiTNode
{
public:
    ElemType val;
    BiTNode *lchild;
    BiTNode *rchild;
    // 创建构造函数
    BiTNode(ElemType x)
    {
        this->val = x;
        this->lchild = NULL;
        this->rchild = NULL;
    }
};
int getMaxWidth(BiTNode *head)
{
    // CASE 1 树空
    if (head == NULL)
    {
        return 0;
    }
    queue<BiTNode *> queue; // 创建层序遍历需要的队列
    unordered_map<BiTNode *, int> LevelMap;
    LevelMap.insert({head, 1}); // 头结点载入 LEVELMAP中
    queue.push(head);           //层序遍历开始 压入头节点
    int curLevel = 1;           // 当前层级
    int curNode = 0;            //当前节点数
    int m = INT8_MIN;
    while (!queue.empty())
    {
        /* 层序遍历 */
        BiTNode *cur = queue.front();
        queue.pop();
        int curNodeLevel = LevelMap.at(cur);
        cout << "已经遍历到" << curNodeLevel << "层级" << endl;
        if (curLevel == curNodeLevel)
        {
            curNode++; //当前节点所在层数等于当前层数 节点个数自增
        }
        else
        {
            m = max(m, curNode); //比较每层的节点个数 最大的留下
            curLevel++;
            curNode = 1; //重置节点个数
        }
        // 配合层级遍历开始计数
        if (cur->lchild != nullptr)
        {
            LevelMap.insert({cur->lchild, curLevel + 1});
            queue.push(cur->lchild);
        }
        if (cur->rchild != nullptr)
        {
            LevelMap.insert({cur->rchild, curLevel + 1});
            queue.push(cur->rchild);
        }
    }
    return max(m, curNode);
}
int main()
{
    // 核心函数开始
    BiTNode *head = new BiTNode('A');
    head->lchild = new BiTNode('B');
    head->rchild = new BiTNode('C');
    int width;
    width = getMaxWidth(head);
    cout << "二叉树宽度结果为:" << endl;
    cout << width << endl;
    return 0;
}
