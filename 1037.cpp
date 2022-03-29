//无法直接运行

#include<bits/stdc++.h>
# define maxsize 50
using namespace std;
struct link
{
    int data;
    link *next;
};
link *store(link *&p1,link *&p2,int num1,int num2,int a[],int b[])
{
    p1=new link;
    p1->data=a[0];
    link *l1,*l2,*s1,*s2;
    s1=p1;
    for(int i=1;i<num1;i++)
    {
        l1=new link;
        l1->data=a[i];
        l1->next=NULL;
        s1->next=l1;
        s1=l1;
    }
    p2=new link;
    p2->data=b[0];
    s2=p2;
    for(int i=1;i<num2;i++)
    {
        l2=new link;
        l2->data=b[i];
        l2->next=NULL;
        s2->next=l2;
    	s2=l2;
    }
    return s1;
}
void Link(link *&p1,link *&p2)
{
    p1->next=p2;
}
void join(link *&p)
{
    link *s=p;
    while(s->next!=NULL)
    {
        link *l1=s->next;
        link *l2=s;
        while(l1!=NULL)
        {
            if(s->data==l1->data)
            {
                l2->next=NULL;
                l2->next=l1->next;
                link *t=l1;
                delete t;
                l1=l2->next;
            }
            else 
            {
                l1=l1->next;
                l2=l2->next;
            }
        }
        s=s->next;
    }
}
int main()
{
    int n,m,a[maxsize],b[maxsize];
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    cin >> m;
    for(int i=0;i<m;i++)
        cin >> b[i];
    link *p1,*p2,*p3;
    p3=store(p1,p2,n,m,a,b);
    Link(p3,p2);
    join(p1);
    while(p1!=NULL)
    {
        cout << p1->data <<' ';
        p1=p1->next;
    }
    return 0;
}


