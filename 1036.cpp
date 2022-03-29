
#include<stdio.h>
#include<stdlib.h>
typedef struct LNode
{
	int data, sum;
	struct LNode *next;
}LinkNode;

void Creat(LinkNode *&L, int n)
{
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

void print(LinkNode *L, int &e, int n)
{
	int max;
	LinkNode *p, *q;
	p = L->next;
	max = L->next->sum;
	while(p != NULL)
	{
		if(max < p->sum)
			max = p->sum;
		p = p->next;
	}
	q = L->next;
 	if(max > n/2)
	{
		while(q->sum != max)
			q = q->next;
		e = max;
	}
	else 
	{
		e = -1;
	}
}
int main()
{
	int n, e;
	scanf("%d", &n);
	LinkNode *L;
	LinkNode *p;
	Creat(L, n);
	merge(L);
	print(L, e, n);
	printf("%d", e);
	return 0;
}


