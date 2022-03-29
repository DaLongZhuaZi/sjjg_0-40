//调试运行闪退

#include<stdio.h>

int main()
{
	int n,k;
	scanf("%d\n%d",&n,&k);
	int m=n;/*计数活着的人*/ 
	int a[10000];
	int i,j=0,b=0;/*j为初始序号，b为循环计数器*/ 
	for(i=0;i<n;i++)
	{
		a[i]=1;/*初始化数组，活着记为1，死者记为0 */ 
	} 
	while(m>1)
	{
		if(a[j]==1)
		{
			b++;
			if(k==b)
		    {
			    a[j]=0;
			    b=0;
			    m--;
		    }
		}
		j++;
		if(j==n)
		{
			j=0;
		}
	} 
	for(i=0;i<n;i++)
	{
		if(a[i]==1)
		printf("%d",i+1);
	}
	return 0;
}

