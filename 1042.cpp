
#include<iostream>
#include"stdlib.h"
#include"stdio.h"
using namespace std;
typedef struct 
{
	char a[100];
	int top;
}SqStack;
int  Optr(SqStack *&l,char x)//运算符先后 
{
	if(l->a[l->top]=='*'&&x=='+')      return 1;
	else if(l->a[l->top]=='*'&&x=='-') return 1;
	else if(l->a[l->top]=='/'&&x=='+') return 1;
	else if(l->a[l->top]=='/'&&x=='-') return 1;
	else if(l->a[l->top]=='-'&&x=='-') return 1;
	else if(l->a[l->top]=='-'&&x=='+') return 1;
	else if(l->a[l->top]=='+'&&x=='-') return 1;
	else if(l->a[l->top]=='+'&&x=='+') return 1;
	else return 0; 
} 
void initl(SqStack *&l)//初始化 
{
	l=(SqStack *)malloc (sizeof(SqStack));
	l->top=-1;
}
void Push(SqStack *&l,char x)//入栈 
{
	l->a[++l->top]=x;
}
void Pop(SqStack *&l,char x)//出栈 
{	
	while(Optr(l,x)==1&&l->top!=-1)//这里要一直判断，原因是若当前运算符的优先级一直比新的栈顶元素高时就要输出运算符栈顶元素
	{
		cout<<l->a[l->top]; 
		l->top--;//顶栈下移 
	}
}
void Print(SqStack *&l)
{
	while(l->top!=-1)
	{
		cout<<l->a[l->top]; 
		l->top--;//顶栈下移 
	}
}
void Destry(SqStack *&l)
{
	free(l);
}
int main()
{
	SqStack * SqStack;
	initl(SqStack);
	char stu[100];
	scanf("%s",stu);
	int i=0;
	while(stu[i]!='\0')
	{
		if(stu[i]!='+'&&stu[i]!='-'&&stu[i]!='*'&&stu[i]!='/'&&stu[i]!='('&&stu[i]!=')')
		cout<<stu[i];
		else if(stu[i]=='(') Push(SqStack,stu[i]);//左括号直接进栈 
		else
		{
			if(SqStack->top==-1) Push(SqStack,stu[i]);//栈为空先入栈
			else //栈不为空进行与顶栈运算符判断 
			{
				if(stu[i]==')')//括号之间的符号全部输出 
				{
					while(SqStack->a[SqStack->top]!='(')
					{
						cout<<SqStack->a[SqStack->top];
						SqStack->top--;
					}
					SqStack->top--;//消除左括号 
				}
				else
				{
					
					if(Optr(SqStack,stu[i])==1)//判断是否出栈 
					{
						Pop(SqStack,stu[i]);//此时符号栈顶元素输出
					}
					else
					{
						Push(SqStack,stu[i]);//此时运算符进栈
					}
				}
			} 
		}
		i++;
	}
	Print(SqStack);//剩下存在符号栈的元素倒叙输出
	Destry(SqStack);
	return 0;
}

