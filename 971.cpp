//调试运行闪退

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
typedef int Datetype;
using namespace std;
typedef struct link{
    Datetype date;
    struct link *lchild;
    struct link *rchild;
}tree;

void creattree(tree *&L)
{
    char c;
    cin>>c;
    if(c=='#')
        L=NULL;
    else
    {
        L = (tree *)malloc(sizeof(tree)) ;
        L->date=c;
        creattree(L->lchild);
        creattree(L->rchild);
    }
}

void destroytree(tree *&L)
{
    if(L!=NULL)
    {
        destroytree(L->lchild);
        destroytree(L->rchild);
        free(L);
    }
}

int deep(tree *L)
{
    int ldep,rdep,max;
    if(L!=NULL)
    {
        ldep=deep(L->lchild);
        rdep=deep(L->rchild);
        max=ldep>rdep?ldep+1:rdep+1;
        return max;
    }
    else
        return 0;
}

int main()
{
    tree *L = NULL;
    int x;
    creattree(L);
    x=deep(L);
    cout<<x;
    destroytree(L);
    return 0;
}