
#include<stdio.h>
char stack[300],ori[300];//用一个stack数组做栈，用一个ori数组存储所有括号
int main()
{
 	int top=0,i=0;
 	scanf("%s",ori);
 	while(ori[i]!='\0')//ori数组没有到最后
 	{
  		if(ori[i]=='('||ori[i]=='[')//压栈
  		{
   			top++;
   			stack[top]=ori[i];
  		}
  		//以下是pop部分
  		else if(ori[i]==']'&&stack[top]=='[')
  			top--;
  		else if(ori[i]==')'&&stack[top]=='(')
   			top--;
  		else//是为了应对这种类型的情况：()))))) 
  		{
   			printf("NO");
   			return 0;
  		}
  		i++;
 	}
 	if(top)//最后top=0的时候表示可以匹配，输出YES，否则输出NO
  		printf("NO");
 	else
  		printf("YES");
  	return 0;
}