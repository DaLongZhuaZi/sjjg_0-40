#include<stdio.h>
int main()
{
	int n;
	int a[100],b[100];
	int del,flag=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&del);
	for(int i=0;i<n;i++)
	{
		if(a[i]!=del)
		{
			b[flag++]=a[i];
		}
	}
	if(flag!=0)
	{
		for(int i=0;i<flag;i++)
		{
			printf("%d ",b[i]);
		}
	}
	else
	printf("-1");
	return 0;
}