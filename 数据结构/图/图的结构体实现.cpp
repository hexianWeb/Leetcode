#include <list>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef int Elemtype;
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
// 主函数创建图类结构体
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
}