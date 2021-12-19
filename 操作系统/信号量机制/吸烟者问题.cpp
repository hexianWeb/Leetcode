#include <stdlib.h>
#include <stdio.h>

#define FLAG 1;

typedef struct
{
    int offer1; //满足一号吸烟者的材料
    int offer2; //二号
    int offer3; //三号
    int finish; //互斥访问信号量
} semaphore;

void P(int x)
{
}
void V(int x)
{
}
// 初始化
void InitSomking(semaphore &S)
{
    S.offer1 = S.offer2 = S.offer3 = S.finish = 0;
}

// 供应者
void provider(semaphore &S)
{
    int i = 0;
    while (1)
    {
        if (i == 0)
        {
            // 将一号所需材料放置到互斥访问空间内
            V(S.offer1);
        }
        else if (i == 1)
        {
            //二号材料
            V(S.offer2);
        }
        else if (i == 2)
        {
            //三号材料
            V(S.offer3);
        }
        // 这里其实不需要额外提供一个互斥信号量
        P(S.finish);
    }
}

// 二号 三号相同
void smoker1(semaphore &S)
{
    while (1)
    {
        P(S.offer1);
        // 从互斥访问空间内取走材料
        V(S.finish);
    }
}