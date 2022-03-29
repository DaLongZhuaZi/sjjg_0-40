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

char getNode(tree *p)
{
	
	if(p!=NULL)
	{
		
		getNode(p->lchild);
		getNode(p->rchild);
		printf("%c", p->elem);
	}
}

int main()
{
	tree *p;
	greate(p);
	getNode(p);
	return 0;
}


