#include <iostream>
using namespace std;
int main()
{
 int n, m, i, s=0;
 while(cin>>n>>m&&n!=0&&m!=0)
 {
  s=0;
  for (i=2; i<=n; i++) //n个人就循环到n，n-1个人就//循环到 n-1
    s=(s+m)%i;
  cout<<s+1<<endl;
 }
 return 0;
}

/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
 int n,m;
 while(scanf("%d%d",&n,&m),(n+m))
 {
  int i,sum=1;
  for(i=2;i<=n;i++)//n个人就循环到n，n-1个人就循环到 n-1
      sum=(sum+m)%i;
      printf("%d\n",sum);
 }
 return 0;
}
*/

/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 10000
__int64 f[M];
int main()
{
 int n,m;
 while(scanf("%d%d",&n,&m),(n||m))
 {
 int i;
 memset(f,0,sizeof(f));
 f[0]=f[1]=0;
 for(i=2;i<=n;i++)
    f[i]=(f[i-1]+m)%i;
    printf("%I64d\n",f[n]+1);
   }
   return 0;
}
*/
