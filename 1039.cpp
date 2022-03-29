
#include<stdio.h>//单链表的信息分类
#include<stdlib.h>
#include<string.h>
typedef struct Linklist
{
    char data;
    struct Linklist *next;

}Linklist;
void Initlist(Linklist *&L)
{
    L=(Linklist *)malloc(sizeof(Linklist));
    L->next=L;
}
void InitlistL(Linklist *&L)
{
    L=(Linklist *)malloc(sizeof(Linklist));
    L->next=NULL;
}
void Creatlist(Linklist *&L,char a[],int n)
{
    Linklist *r=L,*s;
    for(int i=0;i<n;i++)
    {
        s=(Linklist *)malloc(sizeof(Linklist));
        s->data=a[i];
        s->next=r->next;
        r->next=s;
        r=s;
    }
    r->next=NULL;

}
void Sepratelist(Linklist *L,Linklist *&L1,Linklist *&L2,Linklist *&L3)
{
    Linklist *p=L->next,*s1,*s2,*s3,*r1=L1,*r2=L2,*r3=L3;
    while(p!=NULL)//相对有规律
    {
        if(p->data>='0'&&p->data<='9')
        {
            s1=(Linklist *)malloc(sizeof(Linklist));
            s1->data=p->data;
            s1->next=r1->next;
            r1->next=s1;
            r1=s1;
        }
        else if(p->data>='a'&&p->data<='z'||p->data>='A'&&p->data<='Z')
        {
           s2=(Linklist *)malloc(sizeof(Linklist));
            s2->data=p->data;
            s2->next=r2->next;
            r2->next=s2;
            r2=s2;
        }
        else
        {
            s3=(Linklist *)malloc(sizeof(Linklist));
            s3->data=p->data;
            s3->next=r3->next;
            r3->next=s3;
            r3=s3;
        }
        p=p->next;
    }

}
void Putlist(Linklist *L)
{
    Linklist *p=L->next;
    while(p!=L)
    {
        printf("%c",p->data);
        p=p->next;
    }
}
int main()
{
    Linklist *L,*L1,*L2,*L3;
    InitlistL(L);
    Initlist(L1);
    Initlist(L2);
    Initlist(L3);
    int n;
    char a[100];
    for(int i=0;;i++)
    {
        scanf("%c",&a[i]);
        if(a[i]=='\n')
            break;//因为swustoj平台无法用gets函数，所以会相对麻烦一下
    }
    n=strlen(a);
    Creatlist(L,a,n);
    Sepratelist(L,L1,L2,L3);
    Putlist(L1);
    printf("\n");
    Putlist(L2);
    printf("\n");
    Putlist(L3);
    return 0;
}


