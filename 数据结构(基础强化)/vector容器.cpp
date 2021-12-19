#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <algorithm> //排序 sort的头文件
#include <vector>    //变量容器的头文件
using namespace std;

// 利用迭代器将容器中的数据输出
void Print_VALUE(vector<int> obj)
{
    vector<int>::iterator it; //声明一个迭代器 来访问vector容器的元素
    for (it = obj.begin(); it != obj.end(); it++)
    {
        cout << *it << " ";
    }
}
int main()
{
    vector<int> obj;             //创建一个向量存储容器 int
    for (int i = 0; i < 10; i++) //push_back(elem)在数组中添加数据
    {
        obj.push_back(i);
        cout << obj[i] << ",";
    }
    for (int i = 0; i < 5; i++)
    {
        obj.pop_back(); //去掉数组中的最后一个数据
    }
    cout << "\n"
         << endl;

    for (int i = 0; i < obj.size(); i++) //去掉数组中的最后一个数据
    {
        cout << obj[i] << ",";
    }
    cout << "\n"
         << endl;
    obj.clear(); //清楚容器中所有的数据
    if (obj.size() == 0)
    {
        cout << "数组已经空了" << endl;
    }
    obj.push_back(1);
    obj.push_back(3);
    obj.push_back(0);
    sort(obj.begin(), obj.end()); //排序 从小到大
    cout << "从小到大：";
    for (int i = 0; i < obj.size(); i++)
    {
        cout << obj[i] << ",";
    }
    cout << "\n"
         << endl;

    cout << "从大到小" << endl;
    reverse(obj.begin(), obj.end());
    Print_VALUE(obj);
    swap(obj[1], obj[2]);
    Print_VALUE(obj);
    // 3 0 1
    cout << endl;
    cout << obj[obj.size()] << obj.size() << obj[1];
    cout << obj.back();
}