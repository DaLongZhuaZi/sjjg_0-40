
#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	int data;//存储数据
	struct node *next,*piror;//next指向下一个元素，piror指向前一个元素	
};//建立双向链表的结构体
void initlist(node *&l)
{
	l=(node *)malloc(sizeof(node));//申请一个内存空间
	l->next=NULL;//置为空
	l->piror=NULL;//置为空
}
void creatlist(node *&l,int a[],int m)
{
	int i;
	node *p,*q,*r;
	r=l;
	for(i=0;i<m;i++)
	{
		p=(node *)malloc(sizeof(node));
		p->data=a[i];
		r->next=p;
		p->piror=r;
		r=p;
	}//依次链接元素
	r->next=NULL;
}
void displist(node *l)
{
	node *t=l->next;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->next;	
	} 
}
int main()
{
	int m,i;
	int a[200];
	node *l;
	cin>>m;
	for(i=0;i<m;i++)
	{
		cin>>a[i];
	}
	sort(a,a+m);//调用排序函数
	initlist(l);//链表初始化
	creatlist(l,a,m);//创建链表
	displist(l);//打印链表
	return 0;
}

