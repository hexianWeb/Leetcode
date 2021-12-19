// #include <stdlib.h> //注意 malloc和free的函数都在stdlib里 注意引入
// #include <stdio.h>
// #include <string.h> //引入字符串数组

// typedef struct
// {
//     /* data */
//     int data;
//     struct process *L;
// } semaphore;

// void block(semaphore &S)
// {
//     // 阻塞原语
// }

// void wakeup(semaphore &S)
// {
//     //  唤醒原语
// }

// void wait(semaphore &S)
// {
//     S.data--;
//     if (S.data < 0)
//     {
//         /* code */
//         block(S.L);
//     }
// }

// void signal(semaphore &S)

// {
//     S.data++;
//     if (S.data <= 0)
//     {
//         /* code */
//         wakeup(S.L);
//     }
// }