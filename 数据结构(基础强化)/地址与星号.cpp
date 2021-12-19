#include <iostream>

using namespace std;
int main()
{
    int a = 123;
    // &a代表的是a在内存中的地址 也就是123的地址
    cout << "a:" << a << endl
         << "a's address:" << &a << endl;
    // 此时P是一个指针 指向了a所在的位置
    int *p = &a;
    cout << "p:" << p << endl
         << "*p:" << *p << endl; //结果p与a的地址相同
    // 同时p也是一个变量 内存中也有一个地址存储他 但他不是a的地址
    cout << "p's address:" << &p << endl;
    cout << "*&p:" << *&p << endl;
    cout << "**&p:" << **&p << endl;
}