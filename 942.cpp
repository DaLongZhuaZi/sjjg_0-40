
#include<stdio.h>
#include<iostream>
using namespace std;
#define MAX 100
typedef struct{
    char *elem;
    int length;
}SqList;
//初始化
int InitList(SqList &L)
{
    L.elem = new char[MAX];
    if(!L.elem)
    {
        return 0;
    }
    else
    {
        L.length = 0;
        return 1;
    }
}
//获得线性表长度
int GetLength(SqList &L)
{
    return L.length;
}
//创建线性表
void CreatList(SqList &L)
{
    int n;
    cin>>n;
    char str = '0';
    for(int i=0;i<n;i++)
    {
        cin>>str;
        L.elem[i] = str;
    }
    L.length = n;
}
 
void TrvalList(SqList &L)
{
    for(int i=0;i<L.length;i++)
    {
        cout<<L.elem[i];
        if(i!=L.length-1)
        {
            cout<<" ";
        }
    }
    cout<<endl;
}
void ChangList(SqList &L,SqList &L1)
{
    for(int i=0 ; i<L.length;i++)
    {
        L1.elem[i] = L.elem[L.length-1-i];
    }
    L1.length = L.length;
}
int main()
{
    SqList L,L1;
    InitList(L);
    InitList(L1);
    CreatList(L);
    ChangList(L,L1);
    TrvalList(L1);
    return 0;
}