#include <stdlib.h> //注意 malloc和free的函数都在stdlib里 注意引入
#include <stdio.h>
// 注意 一个字符1B 一个指针4B 不要使存储密度过低
typedef struct StringNode
{
    /* data */
    char ch[4];
    struct StringNode *next;
} StringNode, *String;
