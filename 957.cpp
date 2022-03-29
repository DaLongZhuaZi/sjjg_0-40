
#include<stdio.h>
#include<malloc.h>
struct LinkNode
{
	char data;
	struct LinkNode *next;
};
 
struct LinkNode *CreateList(int n)//创建单链表 
{
	char a;
	struct LinkNode *head,*p1,*p2;//声明头指针head和p1，p2操作指针 
	head=p1=(struct LinkNode*)malloc(sizeof(struct LinkNode));//申请空间，并且将head，p1指向这个空间 
	scanf("%c",&a);//用来抵消回车，输入单链表长度后，会有个回车输入，回车也是字符，所以设置一个a，用来储存着个回车，防止将回车符储存在单链表中 
	scanf("%c",&p1->data);//输入第一个数据
	for(int i=1;i<n;i++)//循环储存单链表第二个到最后的所有数据 
	{
		p2=(struct LinkNode*)malloc(sizeof(struct LinkNode));//申请一个新的空间，并且p2指向这个空间 
		p1->next=p2;
		p1=p2;
		scanf("%c",&p1->data);
	}
	p1->next=NULL;
	return head;
}
void ReverseList(struct LinkNode *&head)
{
	struct LinkNode *p1,*p2,*p3;
	p1=head;//p1指第一个结点 
	p2=p1->next;//p2指向第二个结点 
	while(p2!=NULL)
	{
		p3=p2->next;//p3指向第3个结点 
		p2->next=p1;//将p2的next指向p1 ，这样结点的方向就反过来了，本来p2的next是指向p3的，现在指向p1 
		p1=p2;//p1指向p2 ， p2指向p3 。将p1,p2,p3指向整体向后移一位。重复这个循环，就将链表逆置了 
		p2=p3;
	}
	head->next=NULL;//设置原来的头结点的next为空 
	head=p1;//从新设置头结点 
}
int main()
{
	int n;
	struct LinkNode *head,*p;
	scanf("%d",&n);
	head=CreateList(n);//创建单链表 
	ReverseList(head);//逆置单链表 
	p=head;
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
	int n;
	char a[100];
	scanf("%d",&n);
	scanf("%s",a);
	for(int i=n-1;i>=0;i--)
	printf("%c ",a[i]);
}
*/ 