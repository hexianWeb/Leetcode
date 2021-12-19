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
    // 如果当前的节点不是自己的父节点 就递归寻找 直到寻找到根节点
    int find(int x)
    {
        return root[x] == x ? x : find(root[x]);
    }
    void to_union(int x1, int x2)
    {
        //find（x2）就是x2的根节点
        // 只需要将x1的根节点作为x2的根节点即可
        root[find(x2)] = find(x1);
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
    cout << "QuickUnion并查集" << endl;
    cout << uf->is_same(1, 5) << endl;
    cout << uf->is_same(5, 7) << endl;
    cout << uf->is_same(4, 9) << endl;

    uf->to_union(9, 4);

    cout << uf->is_same(4, 9);
}