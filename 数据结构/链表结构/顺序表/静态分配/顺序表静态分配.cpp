#include <stdio.h>
// 定义最大长度
#define MaxSize 10
typedef struct
{
    int data[MaxSize]; //静态数组存放数据元素
    int length;        //顺序表的当前长度
} SqList;              //顺序表的类型定义

void InitList(SqList &L)
{
    for (int i = 0; i < MaxSize; i++)
        printf("value: %d\n ", L.data[i]); //未经行初始化照成内存脏数据
    // L.data[i] = 0;

    L.length = 0;
}
int main()
{
    SqList L;
    InitList(L); //初始化顺序表

    return 0;
}