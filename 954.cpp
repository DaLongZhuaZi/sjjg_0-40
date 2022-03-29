#include<stdio.h>
#include<malloc.h>
struct LinkNode//链表结点 
{
	char data;
	struct LinkNode *next;
};
 
struct LinkNode *InitList(int l)//创建单链表 
{
	char a;
	struct LinkNode *p1,*p2,*head;//声明头指针和p1，p2操作指针 
	head=p1=p2=(struct LinkNode *)malloc(sizeof(struct LinkNode));//申请空间，并且将head，p1，p2指向这个空间 
	scanf("%c",&a);//用来抵消回车，输入单链表长度后，会有个回车输入，回车也是字符，所以设置一个a，用来储存着个回车，防止将回车符储存在单链表中 
	scanf("%c",&p1->data);//输入第一个数据 
	if(l!=1)
	{
		for(int i=1;i<l;i++)//循环储存单链表第二个到最后的所有数据 
		{
			p2=(struct LinkNode *)malloc(sizeof(struct LinkNode));//申请一个新的空间，并且p2指向这个空间 
			p1->next=p2;
			scanf("%c",&a);
			if(a!=' '&&a!='\n')//如果输入的不是空格或者回车，就将它储存起来 
			{
				p2->data=a;
				p1=p2;
			}
			else
			i--;//因为输入的是空格或者回车，不是有效数据，重新进行则个循环，用i--和i++抵消 
		}
	}
	p2->next=NULL;
	return head;
}
int main()
{
	int n,m;
	char a; 
	struct LinkNode *LA,*LB,*p;//声明指针 
	scanf("%d",&n);
	LA=InitList(n);//创建LA单链表 
	scanf("%d",&m);
	LB=InitList(m);//创建LB单链表 
	p=LA;
	while(1)//循环查找单链表LA，直到找到最后一个 
	{
		p=p->next;
		if(p->next==NULL)
		{
			p->next=LB;//将LB单链表接在LA的最后 
			break;
		}
	}
	p=LA;
	while(p!=NULL)
	{
		printf("%c ",p->data);
		p=p->next;
	}
}
/* 
#include<stdio.h>
int main()
{
	char a[100],b[100],k; 
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%c",&k);
		if(k!=' '&&k!='\n')//k!=32&&k!=10
		a[i]=k;
		else
		i--;
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%c",&k);
		if(k!=' '&&k!='\n')
		b[i]=k;
		else
		i--;
	}
	for(int i=0;i<n;i++)
	{
		printf("%c ",a[i]);
	}
	for(int i=0;i<m;i++)
	{
		printf("%c ",b[i]);
	}
}
*/ 