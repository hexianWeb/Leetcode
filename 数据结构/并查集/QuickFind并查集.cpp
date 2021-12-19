#include <vector>
#include <iostream>
using namespace std;
class UnionFind
{
private:
    vector<int> root;

public:
    UnionFind(int size) : root(vector<int>(size))
    {
        // 初始化每一个元素的根节点都为自身
        for (int i = 0; i < size; i++)
        {
            root[i] = i;
        }
    }
    // 常数级别操作
    int find(int x)
    {
        return root[x];
    }
    void to_union(int x1, int x2)
    {
        int rootX = find(x1);
        int rootY = find(x2);
        // 如果两个节点不在同一个集合下
        if (rootX != rootY)
        {
            // 遍历数组 将被合并集合的元素并查集中祖先节点更改为新的集合的根节点
            for (int i = 0; i < root.size(); i++)
            {
                if (root[i] == rootY)
                {
                    root[i] = rootX;
                }
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
    cout << uf->is_same(1, 5) << endl;
    cout << uf->is_same(5, 7) << endl;
    cout << uf->is_same(4, 9) << endl;

    uf->to_union(9, 4);

    cout << uf->is_same(4, 9);
}