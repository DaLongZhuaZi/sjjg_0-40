
#include<stdio.h>
#include<malloc.h>
struct LinkNode//链表节点 
{
	int data;//储存数值 
	struct LinkNode* next;//储存下一个结点指针 
};
 
struct LinkNode *Create(int n)//创建单链表 
{
	struct LinkNode *head,*p1;//声明头指针和p1操作指针 
	head=p1=(struct LinkNode*)malloc(sizeof(struct LinkNode));//申请空间，并且将head，p1指向这个空间 
	for(int i=1;i<n;i++)//循环储存单链表第一个数据和倒数第二个数据 
	{
		scanf("%d",&p1->data);
		p1->next=(struct LinkNode*)malloc(sizeof(struct LinkNode));//储存一个数据后p1->next指向一个新的空间 ,即下一个结点的空间 
		p1=p1->next;//p1指向下一个结点 
	}
	scanf("%d",&p1->data);//储存单链表最后一个数据 
	p1->next=NULL;//后面没有结点了，所以设置为空 
	return head;//返回创建的单链表的头指针 
}
 
bool ListInsert(struct LinkNode *&head,int i,int n)//*&head和*head有区别 ， *&可以改变传入的原指针， *只能改变参数 
{
	struct LinkNode *p,*s;//声明指针 
	p=head;
	if(i<=0||i>n) return false;//如果输入的插入位置小于等于0或者大于单链表长度则输入不合法，返回false 
	else
	{
		if(i==1)//如果插入位置为第一个 ，申请一个新空间储存好插入的值，然后将新空间的指针设置为头指针 
		{
			s=(struct LinkNode*)malloc(sizeof(struct LinkNode));
			scanf("%d",&s->data);
			s->next=p;
			head=s;
		}
		else
		{
			for(int j=0;j<i-2;j++)//找到要插入的位置的前一个指针 
			{
				p=p->next;
			}
			s=(struct LinkNode*)malloc(sizeof(struct LinkNode));//申请新空间，并且将s指向它 
			scanf("%d",&s->data);//储存数据 
			s->next=p->next;//新空间的下一个结点设置为插入位置的结点 
			p->next=s;//设置插入位置的前一个结点的next 
		}
		return true;
	}
	
}
 
int main()
{
	int n;
	int i;
	struct LinkNode *head,*p;//声明头指针和操作指针 
	scanf("%d",&n);
	head=Create(n);//获取头指针的值 
	scanf("%d",&i);
	if(ListInsert(head,i,n))// ListInsert(head,i,n)插入操作 
	{
		p=head;
		while(p!=NULL)
		{
			printf("%d ",p->data);
			p=p->next;
		}
	}
	else
	{
		printf("error!");
	}
}
/*
#include<stdio.h>
int main()
{
	int n,a[100],i,data;
	scanf("%d",&n);
	for(int j=0;j<n;j++)
	{
		scanf("%d",&a[j]);
	}
	scanf("%d %d",&i,&data);
	if(i<=0||i>n)
	printf("error!");
	else
	{
		for(int j=0;j<n;j++)
		{
			if(j==i-1)
			{
				for(int k=n;k>j;k--)
				{
					a[k]=a[k-1];
				}
				a[j]=data;
				break;
			}
		}
		for(int j=0;j<=n;j++)
		{
			printf("%d ",a[j]);
		}
	}
}
*/