#include <stdlib.h>
#include <stdio.h>

#define FLAG 1;
typedef struct
{
    /* data */
    int data;
};

typedef struct
{
    int count;
    int mutex;
    int rw;
    int w;
} smaphore;

void P(int x)
{
}
void V(int x)
{
}
// 代初始化信号量
void InitWriterAndRead(smaphore &S)
{
    S.count = 0;
    S.mutex = FLAG;
    S.rw = FLAG;
    S.w = FLAG;
}

// 写者与任何的进程都互斥
void writer(smaphore &S)
{
    while (1)
    {
        P(S.w);  //增加一个写优先变量 使得读写平衡
        P(S.rw); //访问共享文件
        // 做写入文件操作
        V(S.rw); //释放共享文件
        V(S.w);
    }
}

// 注意 count变量一定要互斥进行访问
void reader(smaphore &S)
{
    while (1)
    {
        P(S.w);
        P(S.mutex);       //避免同步脏数据 互斥执行开关门操作
        if (S.count == 0) // 第一个进来的关写者门，最后一个离开的开写者门
        {
            P(S.rw); //关闭写者门
        }
        S.count++;
        V(S.mutex);
        V(S.w);
        // 开始阅读文件
        P(S.mutex); // 同上
        S.count--;
        if (S.count == 0)
        {
            /* code */
            V(S.rw); //开写者门
        }
        V(S.rw);
    }
}
