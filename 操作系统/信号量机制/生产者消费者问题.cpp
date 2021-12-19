// #include <stdlib.h> //注意 malloc和free的函数都在stdlib里 注意引入
// #include <stdio.h>;
// #include <string.h> //引入字符串数组

// #define NUM 10

// typedef struct
// {
//     int mutex; // 互斥信号访问量 临界缓冲区
//     int empty; // 同步信号量 剩余缓存空间
//     int full;  // 同步信号量 剩余产品数量
// } semaphore;

// void Init_Semaphore(semaphore &S)

// {
//     S.mutex = 1;
//     S.empty = NUM;
//     S.full = 0;
// }

// void producer(semaphore S)
// {
//     while (1)
//     {
//         P(S.empty);
//         P(S.mutex);
//         执行临界区代码
//         V(S.mutex);
//         V(S.full);
//     }
// }

// void consumer(semaphore S)
// {
//     while (1)
//     {
//         P(S.full);
//         P(S.mutex);
//         // 执行临界区代码 取出一个产品
//         V(S.mutex);
//         V(S.empty);
//     }
// }