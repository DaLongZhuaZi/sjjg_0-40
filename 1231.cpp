
#include<stdio.h>
#include<stdlib.h>

typedef struct LNode
{
	int data, sum;
	struct LNode *next;
}LinkNode;

void Creat(LinkNode *&L, int n)
{
	/*创建长度为n的单链表*/ 
	L = (LinkNode *) malloc (sizeof(LinkNode));
	LinkNode *p, *q;
	q = L;
	for(int i=0; i<n; i++)
	{
		p = (LinkNode *) malloc (sizeof(LinkNode));
		scanf("%d", &p->data);
		q->next = p;
		q = p;
	}
	q->next = NULL;
}

void merge(LinkNode *&L)
{
	/*删除L->data相同节点，并计数在L->sum中*/ 
	LinkNode *p, *q, *r;
	p = L->next;
	while(p != NULL)
	{
		q = p;
		p->sum = 1;
		while(q->next != NULL)
		{
			if(p->data == q->next->data)
			{
				p->sum++;
				r = q->next;
				q->next = r->next;
				free(r);
			}
			else	q = q->next;
		}
		p = p->next;
	}
}

void ComNode(LinkNode *L)
{
	/*比较L->sum是否相同，如果相同则输出最小的L->data*/
	LinkNode *p, *q, *r;
	p = L->next;
	r = L->next;
	int maxsum = p->sum;
	int min;
	while( r != NULL)
	{
		if(maxsum < r->sum)
		{
			maxsum = r->sum;
		}
		min = r->data;
		r = r->next;
	}
	while( p != NULL)
	{
		if(p->sum == maxsum && p->data < min)
			min = p->data;
		p = p->next;
	}
	printf("%d", min);
}

int main()
{
	int n;
	LinkNode *L, *p;
	scanf("%d", &n);
	Creat(L, n);
	merge(L);
	ComNode(L);
	return 0;
}




