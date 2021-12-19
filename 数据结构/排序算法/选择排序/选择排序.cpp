#include <stdio.h>
#include <stdlib.h>

#define INITSIZE 10;
typedef struct SSTABLE
{
    int *data;
    int MAXSIZE;
    int Length;
};
// 交换函数 位运算代替
void swap(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
bool InitSSTABLE(SSTABLE &L)
{
    L.Length = 0;
    L.MAXSIZE = INITSIZE;
    L.data = (int *)malloc(L.MAXSIZE * sizeof(int));
    return true;
}
void SelectSort(SSTABLE &L)
{
    for (int i = 0; i < L.Length - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < L.Length - 1; j++)
        {
            /* code */
            if (L.data[j] < L.data[min])
            {
                /* code */
                min = j;
            }
        }
        if (min != i)

        {
            /* code */
            swap(L.data[i], L.data[min]);
        }
    }
}
