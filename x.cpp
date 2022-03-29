#include<stdio.h>
#include<stdlib.h>
int main()
{
 int n,k;
 scanf("%d%d",&n,&k),(n+k);
  int i,sum=1;
  for(i=2;i<=n;i++)
      sum=(sum+k)%i;
    printf("%d\n",sum);
 return 0;
}