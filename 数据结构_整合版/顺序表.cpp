#include <stdlib.h>
#include <stdio.h>

#define MAXSIZE 10
typedef int Elemtype;
typedef struct
{
    Elemtype *data;
    int length;
} SqList;

void InitList(SqList &L)
{
    L.data = (Elemtype *)malloc(MAXSIZE * sizeof(Elemtype));
    L.length = 0;
}

bool ListInsert(SqList &L, int i, Elemtype a)
{
    // 增加程序的健壮性
    if (L.length == MAXSIZE || (i < 1) || (i > L.length + 1))
    {
        return false;
    }
    else
    {
        int j;
        for (int j = L.length - 1; j >= i - 1; j--)
        {
            // 想要插入的数据位置以后的元素以此往后移动一位
            L.data[j + 1] = L.data[j];
        }
        // 将数据插入到i-1号位
        L.data[i - 1] = a;
        L.length++;
    }
    return true;
}

// 寻找低i号位序的元素 取得元素值
int GetElem(SqList L, int i, Elemtype &value)
{
    if (L.length == MAXSIZE || (i < 1) || (i > L.length))
    {
        return -1;
    }

    return 0;
    value = L.data[i];
    return value;
}

void ListDisplay(SqList L)
{
    int i;
    printf("顺序表中的元素有");
    for (i = 0; i < L.length; i++)
    {
        printf("%d\n", L.data[i]);
    }
    printf("\n");
}

// 异或操作 交换两值 不需要额外建立temp变量
void Reverse(SqList &L, int from, int to)
{
    for (int i = 0; i < (from + to) / 2; i++)
    {
        L.data[from + i] = L.data[from + i] ^ L.data[to - i];
        L.data[to - i] = L.data[to - i] ^ L.data[from + i];
        L.data[from + i] = L.data[from + i] ^ L.data[to - i];
    }
}
bool Converse(SqList &L, int p)
{
    Reverse(L, 0, p - 1);
    Reverse(L, p - 1, L.length - 1);
    Reverse(L, 0, L.length - 1);
}

int M_search(SqList &A, SqList &B)
{
    // A1 B1分别表示首数
    int A1 = 0;
    int B1 = 0;
    // A2 B2 表示尾数
    int A2 = A.length;
    int B2 = B.length;
    // 中位数
    int MA, MB;
    while (A.data[A1] != A2 || B1 != B2)
    {
        MA = (A1 + A2) / 2;
        MB = (B1 + B2) / 2;
        // 情况一 AB序列中位数相等
        if (MA == MB)
        {
            return MA;
        }
        if (MA > MB)
        {
            if ((A1 + A2) % 2 == 0)
            {
                A2 = MA;
                B1 = MB;
            }
            else
            {
                A2 = MA + 1;
                B1 = MB;
            }
        }
        else
        {
            if ((A1 + A2) % 2 == 0)
            {
                A1 = MA;
                B2 = MB;
            }
            else
            {

                A1 = MA;
                B2 = MB - 1;
            }
        }
    }
    return A.data[A1] < B.data[B2] ? A.data[A1] : B.data[B2];
}

int main()
{
    SqList L;
    InitList(L);
    for (int i = 0; i <= MAXSIZE; i++)
    {
        ListInsert(L, i, i);
    }

    ListDisplay(L);
    return 0;
}