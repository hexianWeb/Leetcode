#include <vector>
#include <iostream>
using namespace std;
class UnionFind
{
private:
    vector<int> root;
    vector<int> rank; //标记当前所在集合的高度（秩）

public:
    // 冒号后 初始化 两个数组
    UnionFind(int size) : root(vector<int>(size)), rank(vector<int>(size))
    {
        // 初始化每一个元素的根节点都为自身
        for (int i = 0; i < size; i++)
        {
            root[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x)
    {
        return root[x] == x ? x : find(root[x]);
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
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }
    bool is_same(int e1, int e2)
    {
        return find(e1) == find(e2);
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