#include<stdio.h>
#include<stdlib.h>
  
#define STACK_SIZE  100
#define STCK_INCREMENT  10
  
typedef struct 
{
      int *base;
     int *top;
     int stacksize;
}SqStack;
 
void InitStack(SqStack &S)
{
     //为栈申请空间
     S.base = (int*)malloc(STACK_SIZE * sizeof(int));
     if (!S.base)
     {
         exit(-2);
     }
     S.top = S.base;
     S.stacksize = STACK_SIZE;
}
 
 
void Push(SqStack &S, int e)
{
    if ((S.top - S.stacksize) >= S.base) //栈满追加空间
    {
        S.base = (int*)realloc(S.base, (S.stacksize + STCK_INCREMENT) * sizeof(int));
        if (!S.base)
        {
            exit(-2);
        }
        S.top = S.base + S.stacksize;
        S.stacksize += STCK_INCREMENT;
    }

    *S.top++ = e;
}

int Pop(SqStack &S, int &e)
{
    if (S.base == S.top)
    {
        return 0;
    }
    e = *--S.top;
    return 1;
}
 
 
int main()
{
    int n, e;
    scanf("%d", &n);
    SqStack S;
    InitStack(S);
    while (n)
    {
        Push(S, n % 2);
        n = n / 2;
    }
    
    while (1)
    {
        int status = Pop(S, e);
        if (!status)
        {
            break;
        }
        printf("%d", e);
    }
    return 0;
}

/*
 方法二：

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> mstack;

    int n;
    cin>>n;
    while(n)
    {
        mstack.push(n%2);
        n = n/2;
    }

    while(!mstack.empty())
    {
        cout<<mstack.top();
        mstack.pop();
    }
    return 0;
}
*/