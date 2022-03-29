//调试运行闪退

#include<cstdio>
using namespace std;
const int N=105;
int ans[N];
struct tree
{
    int dat;
    tree *lc,*rc;
    tree()
    {
        lc=NULL,rc=NULL;
    }
}*root;
int build(tree *a,int h)
{
    char ch;
    scanf("%c",&ch);
    if(ch=='#')
    {
        a=NULL;
        return 0;
    }
    ans[h]++;
    a=new tree();
    a->dat=ch-'0';
    int h1=build(a->lc,h+1),h2=build(a->rc,h+1);
    return h1>h2?(h1+1):(h2+1);
}
int main()
{
    int H=build(root,1),maxn=0;
    for(int i=1;i<=H;i++)
        maxn=maxn>ans[i]?maxn:ans[i];
    printf("%d",maxn);
}

