//调试运行闪退

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    char elem;
    struct node *lchild;
    struct node *rchild;
}tree;

int count = 0;
void greate(tree *&p)
{
    char elem;
    scanf("%c",&elem);
    if(elem=='#')
    {
    	count++;
    	p=NULL;
	}
    
    else
    {
        p=(tree *)malloc(sizeof(tree));
        p->elem=elem;
        greate(p->lchild);
        greate(p->rchild);
    }
}

int main()
{
	tree *p;
	greate(p);
	printf("%d", count);
	return 0;
}


