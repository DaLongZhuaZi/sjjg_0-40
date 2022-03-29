
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define Max 100
#define Space (Squeue *)malloc(sizeof(Squeue))
typedef struct//定义节点
{
    int queue[Max];
    int rear;
    int front;
    int Maxsize;
}Squeue;
void Init(Squeue *&Q,int n)//初始化
{
    Q=Space;
    Q->rear=0;
    Q->front=0;
    Q->Maxsize=n+1;
}
bool Empty(Squeue *Q)//判空
{
    if(Q->rear==Q->front)
        return 0;
    else
        return 1;
}
void Intoqueue(Squeue *&Q,int x)//进队
{
    if((Q->rear+1)%Q->Maxsize!=Q->front)
    {
        Q->queue[Q->rear]=x;
        Q->rear=(Q->rear+1)%Q->Maxsize;
    }
}
void Putqueue(Squeue *&Q,int d)//出队
{
    if(Q->rear!=Q->front)
    {
        d=Q->queue[Q->front];
         Q->front=(Q->front+1)%Q->Maxsize;
    }
}
void Gettop(Squeue *&Q,int d)//取队头元素
{
    if(Q->rear!=Q->front)
    {
        d=Q->queue[Q->front];
        printf("%d ",d);
    }
}
int main()
{
    Squeue *Q;
    int n,j=1,x=1,d;
    scanf("%d",&n);
    Init(Q,n);
    while(j!=n+1)
    {
        int x1=1;//注意变量位置
        for(int i=0;i<j;i++)
        {
           if(i==0)//第一个元素为1进队
               Intoqueue(Q,x);
           else
           {
               x1=x1*(j-i)/i;//按规律来
               Intoqueue(Q,x1);
           }
        }
        while(Empty(Q))//输出（出队）
        {
            Gettop(Q,d);
            Putqueue(Q,d);
        }
        printf("\n");
        j++;

    }
    return 0;
}


