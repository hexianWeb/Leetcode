#include <stdlib.h> //注意 malloc和free的函数都在stdlib里 注意引入
#include <stdio.h>

#define InitSize 10

typedef struct
{
    int *data;
    int MaxSize;
    int length;
} SSTable;

void InitList(SSTable &T)
{
    T.MaxSize = InitSize;
    T.data = (int *)malloc(T.length * sizeof(int));
}

void ShellSort(SSTable &T)
{
    int d, i, j;
    for (d = T.length / 2; d >= 1; d = d / 2)
    {
        /* code */
        for (i = d + 1; i < T.length; ++i)
        {
            /* code */
            if (T.data[i] < T.data[i - d])
            {
                /* code */
                T.data[0] = T.data[i];
                for (j = i - d; j > 0 && T.data[j] > T.data[0]; j -= d)
                {
                    /* code */
                    T.data[j + d] = T.data[j];
                }
                T.data[j + d] = T.data[0];
            }
        }
    }
}
// 不稳定！
// 65 49 49|
// 49| 49 65