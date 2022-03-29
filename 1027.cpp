//调试运行闪退

#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main()
{
	int m,n,k;
	cin>>m;
	int i;
	char str1[105],str2[105];
	for(i=0;i<m;i++)
		cin>>str1[i];
	cin>>n;
	for(i=0;i<n;i++)
		cin>>str2[i];
	cin>>k;
	cout<<str1[(k-1)%m]<<" "<<str2[(k-1)%n];
	return 0;
}