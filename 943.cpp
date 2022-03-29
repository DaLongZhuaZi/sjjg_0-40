#include<stdio.h>
#include<malloc.h>
#define MAxSize 1000
typedef struct//顺序表
{
    int data[MAxSize];
    int length;
}SqList;
void init(SqList*&L)
{
    L=(SqList*)malloc(sizeof(SqList));
    L->length=0;
}
void Insert(SqList*&L,int num)
{
    L->data[L->length]=num;
    L->length++;
    //长度增一，新数据要插入的位置即为长度的值表示的位置
}
void put(SqList*&L,int item,int data)
{
    int i=0;
    bool flag=true;
    while(L->data[i]!=item)
    //令i=0，即从头开始，查找指定数据
    {
        i++;
        if(i>=L->length)
        //若没找到，令flag==false，并退出循环，若不退出，则死循环
        {
            flag=false;
            break;
        }
    }
    if(flag)//如果找到指定数据
    {
        L->length++;//线性表多了一个元素，即长度增一
        for(int j=L->length-1;j>=i;j--)
        //把指定数据之后的数，后移一个位置（包括指定数据）
        {
            L->data[j]=L->data[j-1];
        }
        L->data[i]=data;
        //指定数据的位置上的数，改为要插入的新数据
        for(int j=0;j<L->length;j++)//从头到尾输出
        {
            printf("%d ",L->data[j]);
            //多输出一个空格，学校oj可以过
            //有时正常输出，反而会提示输出格式错误
        }
    }else//如果没有找到指定的数据，则把数据插入到末尾
    {
        Insert(L,data);//利用插入函数插入到线性表末尾
        for(int j=0;j<L->length;j++)//依次输出
        {
            printf("%d ",L->data[j]);
            //多输出一个空格，学校oj可以过
            //有时正常输出，反而会提示输出格式错误
        }
    }

}
int main()
{
    SqList*L;
    init(L);//初始化线性表
    int n,item,data,num;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num);
        Insert(L,num);
        //将数据一个个插入线性表，无需使用数组存了数据再插入
    }
    scanf("%d",&item);
    scanf("%d",&data);
    put(L,item,data);//尝试把元素放入线性表
}


