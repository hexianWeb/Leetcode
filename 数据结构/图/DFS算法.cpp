#include <list>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

class Edge;

// 节点类
class Node
{
public:
    int value;
    int in;             //入度
    int out;            //出度
    list<Node *> nexts; //邻接点集
    list<Edge *> edges; //邻接边集合
    // 构造函数
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
    int weight;
    Node *from;
    Node *to;
    Edge();
    Edge(int _w, Node *from, Node *to)
    {
        this->from = from;
        this->to = to;
        this->weight = _w;
    }
};

// 图类
class Graph
{
public:
    unordered_map<int, Node *> nodes;
    unordered_set<Edge *> edges;
};

// 图的构建算法**************************************************
Graph *CreateGraph(int matrix[][3], int n)
{
    Graph *graph = new Graph;
    // 解析
    for (int i = 0; i != n; i++)
    {
        int weight = matrix[i][0];
        int from = matrix[i][1];
        int to = matrix[i][2];
        if (graph->nodes.find(from) == graph->nodes.end())
        {
            graph->nodes[from] = new Node(from);
        }
        if (graph->nodes.find(to) == graph->nodes.end())
        {
            graph->nodes[to] = new Node(to);
        }
        Node *fromNode = graph->nodes[from];
        Node *toNode = graph->nodes[to];
        Edge *newEdge = new Edge(weight, fromNode, toNode);

        // 更新from节点的值
        fromNode->nexts.push_back(toNode);
        fromNode->out++;
        fromNode->edges.push_back(newEdge);

        // 更新 to节点
        toNode->in++;

        graph->edges.insert(newEdge);
    }
    return graph;
}

// 深度优先遍历核心算法-----------------------------------------------
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
    cout << "深度度优先算法遍历结果" << endl;
    DFS(graph->nodes[1]);
}