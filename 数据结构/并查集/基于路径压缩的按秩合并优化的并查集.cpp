#include <vector>
#include <iostream>
using namespace std;

// 他有着 路径压缩的find函数
// 以及按秩合并的union函数
class UnionFind
{
private:
    vector<int> root;
    // 添加了rank数组 来记录每个顶点的高度也就是每个顶点的秩
    vector<int> rank;

public:
    UnionFind(int size) : root(vector<int>(size)), rank(vector<int>(size))
    {
        for (int i = 0; i < size; i++)
        {
            root[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x)
    {
        if (root[x] == x)
        {
            return x;
        }
        return root[x] = find(root[x]);
    }

    void to_union(int x1, int x2)
    {
        int rootX = find(x1);
        int rootY = find(x2);
        if (rootX != rootY)
        {
            if (rank[rootX] > rank[rootY])
            {
                root[rootY] = rootX;
            }
            else if (rank[rootX] < rank[rootY])
            {
                root[rootX] = rootY;
            }
            else
            {
                root[rootX] = rootY;
                rank[rootY] += 1;
            }
        }
    }
    bool is_same(int x, int y)
    {
        return find(x) == find(y);
    }
};
int main()
{
    UnionFind *uf = new UnionFind(10);
    uf->to_union(1, 2);
    uf->to_union(2, 5);
    uf->to_union(5, 6);
    uf->to_union(6, 7);
    uf->to_union(3, 8);
    uf->to_union(8, 9);
    cout << "按秩合并并查集" << endl;
    cout << uf->is_same(1, 5) << endl;
    cout << uf->is_same(5, 7) << endl;
    cout << uf->is_same(4, 9) << endl;

    uf->to_union(9, 4);

    cout << uf->is_same(4, 9) << endl;
}