#include <unordered_map>
#include <list>
using namespace std;
class Node
{
public:
    int value;
    int in;
    int out;
    Node(int value)
    {
        this->value = value;
        this->in = in;
        this->out = out;
    }
};

// 简易版 并查集的实现
class MySets
{
public:
    unordered_map<Node *, list<Node *>> setMap;

    //创建并查集
    MySets(list<Node *> nodes)
    {
        // 遍历所有节点 并将每个节点设置一个list 用来存储当前所在集合的所有节点
        for (Node *cur : nodes)
        {
            list<Node *> set;
            set.push_back(cur);
            // 将节点与set集合摄入setMap中
            setMap.insert({cur, set});
        }
    }
    // 判断两个节点是否在同一个并查集中
    bool isSameSet(Node *from, Node *to)
    {
        list<Node *> fromSet = setMap[from];
        list<Node *> toSet = setMap[to];
        // 核心逻辑 判断两者的并查集合地址是否一直
        return fromSet == toSet;
    }

    // 合并两个并查集合
    void unionSet(Node *from, Node *to)
    {
        list<Node *> fromset = setMap[from];
        list<Node *> toSet = setMap[to];
        // 将后者的元素加入到前者的集合中 且后插法不改版list的集合地址
        for (Node *node : toSet)
        {
            fromset.push_back(node);
            setMap.insert({node, fromset});
        }
    }
};