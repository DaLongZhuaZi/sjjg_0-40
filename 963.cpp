
#include<iostream> 
using namespace std;
# define size 50
int s=0,i=0,cg=0,w[size]; 
void match(int W,int n,int s,int i)
{
	if(s==W) 
	{
		cg=1;
		return ;
	}
	else if(s>W) return;  //回溯
	else 
	{
		for(i;i<n;i++)
		{
			match(W,n,s+w[i],i+1); //继续递归调用装入物品
		}
	}	
}
int main()
{
	int W,num;
	cin >> W >> num;
	for(int j=0;j<num;j++)
		cin >> w[j];
	match(W,num,s,i);
	if(cg==1)
	cout << "yes!";
	else cout << "no!";
	return 0;
}

