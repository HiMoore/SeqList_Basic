#include <stdio.h>
#include <stdlib.h>

#define Maxsize 100
#define overflow 0
#define underflow 0
#define true 1
#define false 0
#define error 0
#define ok 1

typedef int Elemtype;
typedef struct
{
    Elemtype data[Maxsize];
    int length;
}SeqList;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void Init_Seqlist(SeqList *L);
void Build_Seqlist(SeqList *L, Elemtype *A, int n);
int Find_X(SeqList *L, Elemtype X);
int Insert_Seqlist(SeqList *L, Elemtype X, int i);
int Delete_X(SeqList *L, Elemtype X);
int Delete_i(SeqList *L, int i);
void Traver_Seqlist(SeqList *L);
void Reverse_Seqlist(SeqList *L);

int main()
{
    int A[10] = {1,2,3,4,5,6,7,8,9,0};
    SeqList List;
    Init_Seqlist(&List);
    Build_Seqlist(&List, A, 10);
    Traver_Seqlist(&List);
    Insert_Seqlist(&List, 8,8);
    Delete_i(&List, 8);
    Delete_X(&List, 8);
    Reverse_Seqlist(&List);
    Traver_Seqlist(&List);
    int p = Find_X(&List, 5);
    printf("location is %d\n", p);
    return 0;
}


//初始化
void Init_Seqlist(SeqList *L)
{
    L -> length = 0;
}

//建立表
void Build_Seqlist(SeqList *L, Elemtype *A, int n)
{
    int i=0;
    while(n<Maxsize && L->length<n)
    {
        L->data[L->length] = A[i++];
        L->length++;
    }

}

//查找值为value的元素
int Find_X(SeqList *L, Elemtype X)
{
    if(L->length == 0)
        return underflow;
    int i=1;
    while(i<(L->length) && L->data[i-1] != X)
        i++;
    if(i == L->length)
        return false;
    else return i;
}

//在位置i插入一个元素x
int Insert_Seqlist(SeqList *L, Elemtype X, int i)
{
    if(i == Maxsize)
        return overflow;
    if(i<0 || i > L->length)
        return error;
    else
    {
        int j;
        for(j=L->length; j>i-1; j--)
        {
            L->data[j] = L->data[j-1];
        }
        L->data[j] = X;
        L->length++;
        return ok;
    }
}

//删除值为X的元素
int Delete_X(SeqList *L, Elemtype X)
{
    if(L->length == 0)
        return underflow;
    int i = Find_X(L, X);
    if(i != 0)
    {
        int j;
        for(j=i; j < L->length; j++)
        {
            L->data[j-1] = L->data[j];
        }
        L->length--;
        return ok;
    }
    else
        return false;
}

//删除第i个元素
int Delete_i(SeqList *L, int i)
{
    if(i<1 || i>L->length)
        return overflow;
    int j;
    for(j=i; j<L->length; j++)
        L->data[j-1] = L->data[j];
    L->length--;
    return ok;
}

//遍历输出表中元素和长度
void Traver_Seqlist(SeqList *L)
{
    if(L->length == 0)
        printf("This is an empty seqlist!");
    else
    {   int i;
        for(i=0; i<L->length; i++)
            printf("%d ", L->data[i]);
        printf("\n");
        printf("The length of Seqlist is %d\n", L->length);
    }
}

//逆置
void Reverse_Seqlist(SeqList *L)
{
    int i;
    for(i=0; i<(L->length)/2; i++)
        swap(&L->data[i], &L->data[L->length-i-1]);
}

//清空线性表
void Destroy_List(SeqList *L)
{
    L->length = 0;
}
