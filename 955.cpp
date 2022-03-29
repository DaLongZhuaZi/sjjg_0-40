
#include<stdio.h>
#include<malloc.h>
struct LinkNode
{
	int data;
	struct LinkNode *next;
};
 
struct LinkNode *Create(int n)
{
	struct LinkNode *head,*p1,*p2;//声明头指针和p1，p2操作指针 
	head=p1=p2=(struct LinkNode*)malloc(sizeof(struct LinkNode));//申请空间，并且将head，p1，p2指向这个空间 
	scanf("%d",&p1->data);//储存第一个数据 
	for(int i=1;i<n;i++)//循环储存单链表第二个到最后的所有数据 
	{
		p2=(struct LinkNode*)malloc(sizeof(struct LinkNode));//申请一个新的空间，并且p2指向这个空间 
		p1->next=p2;
		p1=p2;
		scanf("%d",&p1->data);
	}
	p1->next=NULL;
	return head;
}
int main()
{
	int n,i;
	struct LinkNode *head,*p;
	scanf("%d",&n);
	head=Create(n);
	scanf("%d",&i);
	if(i<=0||i>n)
	printf("error");
	else
	printf("ok");
 } 
 
/* 
#include<stdio.h>
int main()
{
	int n,a[100],t;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&t);
	if(t<=0||t>n)
	printf("error");
	else
	printf("ok");
}
*/ 