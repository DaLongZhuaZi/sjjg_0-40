
#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct sq
{
	int data[500];
	int front,rear,MaxSize;
} Sqqueue;

void init(Sqqueue *&Q,int n)
{
	Q=(Sqqueue*)malloc(sizeof(Sqqueue));
	Q->MaxSize=n;
	Q->front=0;
	Q->rear=0;
}//初始化环形队列

void insert(Sqqueue *&Q,int e) 
{
	if((Q->rear+1)%Q->MaxSize!=Q->front)
	{
	Q->rear=(Q->rear+1)%Q->MaxSize;
	Q->data[Q->rear]=e;		
	}

}//入队列

 int deinsert(Sqqueue *&Q) 
{
	if(Q->rear==Q->front)
		exit(0);
	Q->front=(Q->front+1)%Q->MaxSize;
	int c=Q->data[Q->front];
	return c;
}//入队列
int main()
{
	int n,m,c[100]={0},j=0;
	Sqqueue *Q;
	cin>>n>>m;

	init(Q,n);
	for(int i=0;i<m;i++)
{
	int num;
	char s[5];
	cin>>s;
	if(s[0]=='i')
	{
	cin>>num;
	insert(Q,num);	
	}
	else if(s[0]=='o')
	{
	deinsert(Q);
		}	
}
for(j=0;j<n;j++)
{
	c[j]=deinsert(Q);
	j++;
}

for(j=0;j<100;j++)
{

	if(c[j]!=0)
	{
		cout<<c[j];
		cout<<" ";
	}
	
		
}
return 0;
}

