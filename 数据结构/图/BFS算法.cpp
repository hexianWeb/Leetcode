#include <list>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

class Edge;
// 结点类
class Node
{
public:
    int value;
    int in;             //入度
    int out;            //出度
    list<Node *> nexts; // 此节点的邻居结点（有向边中 发散出的能到达的顶点）
    list<Edge *> edges; // 节点触发 发散出边的集合
    Node(int val)
    {
        this->value = val;
        this->in = 0;
        this->out = 0;
    }
};

// 边类
class Edge
{
public:
    int weight; //权值
    Node *from; //发散节点
    Node *to;   //到达节点
    Edge();
    Edge(int _w, Node *_from, Node *_to)
    {
        this->from = _from;
        this->to = _to;
        this->weight = _w;
    }
};

// 图类
class Graph
{
public:
    // 点序号和节点的映射集合
    unordered_map<int, Node *> nodes;
    // 边的集合
    unordered_set<Edge *> edges;
};

// 创建一个图

Graph *CreateGraph(int matrix[][3], int n)
{
    // 创建结构体
    Graph *graph = new Graph;
    // 解析矩阵中的各列 拿到
    for (int i = 0; i != n; i++)
    {
        int weight = matrix[i][0];
        int from = matrix[i][1];
        int to = matrix[i][2];
        //如果当前节点第一次在便利过程中出现 则将节点新建填入图像的map集合中
        //    入度节点首次出现
        if (graph->nodes.find(from) == graph->nodes.end())
        {
            graph->nodes[from] = new Node(from);
        }
        //      出度节点首次出现
        if (graph->nodes.find(to) == graph->nodes.end())
        {
            graph->nodes[to] = new Node(to);
        }
        // 建立当前这一行所表示的边
        // 利用已经取得的权重W 入度F 出度T
        Node *fromNode = graph->nodes[from];
        Node *toNode = graph->nodes[to];
        // 建立边
        Edge *newEdge = new Edge(weight, fromNode, toNode);

        // 更新节点fromNode

        // next邻节点领域
        // 注意 这里是单项边 from 指向to from可加 to不用
        fromNode->nexts.push_back(toNode);
        // 更新fromNode的出度
        fromNode->out++;
        // 最后关联这条边
        fromNode->edges.push_back(newEdge);

        // 更新节点tonode 的入度
        toNode->in++;

        // 将边载入边集
        graph->edges.insert(newEdge);
    }
    return graph;
}

// --------------------------------------------------------------------
// 宽度优先遍历核心算法

void BFS(Node *node)
{
    // 类似树的层序遍历
    queue<Node *> queue;
    // 判断当前是否出现过这个节点了
    unordered_set<Node *> set;
    if (node == NULL)
    {
        return;
    }
    // 将当前节点载入队列和set集合中
    queue.push(node);
    set.insert(node);
    while (!queue.empty())
    {
        Node *cur = queue.front();
        queue.pop();
        // 对当前元素进行操作
        cout << cur->value << " ";
        // 对当前节点的临接点集进行遍历操作
        for (Node *next : cur->nexts)
        {
            // 如果当前节点的邻接节点未出现过
            if (set.find(next) == set.end())
            {
                // 将节点载入队列以及set集合中
                queue.push(next);
                set.insert(next);
            }
        }
    }
    cout << endl;
}
// / 深度优先遍历核心算法-- ---------------------------------------------
void DFS(Node *node)
{
    // 记录当前以及经过的路径
    stack<Node *> stack;
    // 记录当前是否经过过某个节点
    unordered_set<Node *> set;

    if (node == NULL)
    {
        return;
    }
    // 将当前节点载入队列
    stack.push(node);
    set.insert(node);
    cout << node->value << " ";
    while (!stack.empty())
    {
        Node *cur = stack.top();
        stack.pop();

        // 遍历当前节点的邻接节点集合
        for (Node *next : cur->nexts)
        {
            // 如果该邻接节点没有出现过
            if (set.find(next) == set.end())
            {
                // set集合标记该邻接节点
                set.insert(next);
                // 将当前节点以及邻接节点压会栈中
                stack.push(cur);
                stack.push(next);
                cout << next->value << " ";
                break;
            }
        }
    }
}

int main()
{
    // 试着建立一张三条边的有向图
    // 设定基本数据
    int matrix[3][3];
    matrix[0][0] = 1;
    matrix[0][1] = 1;
    matrix[0][2] = 2;

    matrix[1][0] = 1;
    matrix[1][1] = 2;
    matrix[1][2] = 3;

    matrix[2][0] = 1;
    matrix[2][1] = 1;
    matrix[2][2] = 3;

    // 建立
    Graph *graph = CreateGraph(matrix, 3);

    // cout << "第一个节点为：" << graph->nodes[3]->value;
    cout << "宽度优先算法遍历结果" << endl;
    BFS(graph->nodes[1]);

    cout << "深度优先算法便利结果" << endl;
    DFS(graph->nodes[1]);
}