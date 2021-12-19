// 7 10 |13 19 16 20 |27 22 30| 40 36
//  <=10    <=20        <=30    <=40

#include <stdlib.h> //注意 malloc和free的函数都在stdlib里 注意引入
#include <stdio.h>

// 结构体定义
typedef struct
{
    // 定义最大的关键字值
    int maxValue;
    // 定义各个分块存储区间
    int low, high;
};

int List[100];

/*
    分块查找
*/
