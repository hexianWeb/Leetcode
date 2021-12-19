#include <stdlib.h> //注意 malloc和free的函数都在stdlib里 注意引入
#include <stdio.h>

#define MaxSize 100

struct TreeNode
{
    /* data */
    int value;
    bool isEmpty; // 判断节点是否为空
};
// 基本应用很少出现