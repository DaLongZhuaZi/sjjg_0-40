
#include<iostream>
#include <stdlib.h>
using namespace std;
typedef struct
{
    int data[100];
    int length;
}List;
void init(List *&L)//初始化
{
    L = (List*)malloc(sizeof(List));
    L->length = 0;
}
void add(List *&L,int a[],int length)//添加元素
{
    for(int i=0;i<length;i++)
    {
        L->data[i] = a[i];
    }
    L->length = length;
}
void combine(List *&L1,List *&L2,List*&L3)//合并后排序
{
    for(int i=0;i<L1->length;i++)
    {
        L3->data[L3->length++] = L1->data[i];
    }
    for(int i=0;i<L2->length;i++)
    {
        L3->data[L3->length++] =L2->data[i];
    }
    for(int i=0;i<L3->length;i++)
    {
        for(int j=i;j<L3->length;j++)
        {
            if(L3->data[i]>L3->data[j])
            {
                int temp = L3->data[i];
                L3->data[i] = L3->data[j];
                L3->data[j]= temp;
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int m;
    cin>>m;
    int b[m];
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    List *L1,*L2,*L3;
    init(L1);
    init(L2);
    init(L3);
    add(L1, a, n);
    add(L2, b, m);
    combine(L1, L2, L3);
    for(int i=0;i<L3->length;i++)
    {
        cout<<L3->data[i]<<" ";
    }
    return 0;
}