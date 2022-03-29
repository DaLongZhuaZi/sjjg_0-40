//无法直接调试运行

#include<bits/stdc++.h> 
# define maxsize 50
using namespace std;
struct link
{
	int data;
	link *next;
};
void creat(link *&p)
{
	p=new link;
	p->next=NULL;
}
void store(link *&p,int a[],int num)
{
	link *l=p,*s;
	for(int i=0;i<num;i++)
	{
		s=new link;
		s->data=a[i];
		s->next=NULL;
		l->next=s;
		l=s;
	}
}
void Delete(link *&p,int num1,int num2)
{
	link *l=p->next;
	link *s1=p;
	while(l!=NULL)
	{
		if(l->data<=num2&&l->data>=num1)
		{
			s1->next=l->next;
			l=s1->next;
		}
		else 
		{
			s1=s1->next;
			l=l->next;
		}
	}
}
void Cout(link *&p)
{
	link *l=p->next;
	while(l!=NULL)
	{
		cout << l->data <<' ';
		l=l->next;
	}
}
int main()
{
	int n,a[maxsize],num1,num2;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	cin >> num1 >> num2;
	link *p;
	creat(p);
	store(p,a,n);
	Delete(p,num1,num2);
	Cout(p);
	return 0;
}

