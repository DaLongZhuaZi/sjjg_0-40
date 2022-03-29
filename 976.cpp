//调试运行闪退

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    char elem;
    struct node *lchild;
    struct node *rchild;
}tree;

void greate(tree *&p)
{
    char elem;
    scanf("%c",&elem);
    if(elem=='#')
    p=NULL;
    else
    {
        p=(tree *)malloc(sizeof(tree));
        p->elem=elem;
        greate(p->lchild);
        greate(p->rchild);
    }
}

int count = 0;
void OneNode(tree *p)
{
	
	if(p!=NULL)
	{
		if(p->lchild != NULL && p->rchild == NULL || p->lchild == NULL && p->rchild != NULL)
		{
			count++;
		}
		OneNode(p->lchild);
		OneNode(p->rchild);
	}
}

int main()
{
	tree *p;
	greate(p);
	OneNode(p);
	printf("%d", count);
	return 0;
}


