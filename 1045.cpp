
#include<stdio.h>//集合交运算实现
#include<stdlib.h>//和1037题类似
typedef struct
{
    int data[100];
    int length;

}Sqlist;
void Initlist(Sqlist *&L)
{
    L=(Sqlist *)malloc(sizeof(Sqlist));
    L->length=0;
}
void Jiaolist(Sqlist *&L,Sqlist *&L1,Sqlist *&L2,int n,int m)
{
    int k=0;//k表示L的长度
   for(int i=0;i<n;i++)
   {
       int flag=0;//统计L1中某一元素等于L2中元素个数
       for(int j=0;j<m;j++)
       {
           if(L1->data[i]==L2->data[j])
           {
               flag++;
           }
       }
       if(flag>0)//如果L1中这一元素存在与L2中的元素相同的话，则将其复制到L中
       {
           L->data[k]=L1->data[i];
           k++;
       }
   }
   for(int m=0;m<k;m++)
   {
       printf("%d ",L->data[m]);
   }
}

int main()
{
    Sqlist *L1,*L2,*L;
    Initlist(L1);
    Initlist(L2);
    Initlist(L);
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&L1->data[i]);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&L2->data[i]);
    }
    Jiaolist(L,L1,L2,n,m);
    return 0;
}


