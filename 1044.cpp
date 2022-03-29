#include <iostream>
#include <cstdlib>
using namespace std;


typedef struct stackList
{
    int *top, *base;
    int stack_size;
}SqStack;


void Init_stack(SqStack &s, int n)
{
    s.base = (int*)malloc(n*sizeof(int));
    if (!s.base)
    {
        exit(-2);
    }
    s.top = s.base;
    s.stack_size = n;
}

void Push(SqStack &s, int e)
{
    if(s.top - s.base == s.stack_size)
    {
        exit(-2);
    }
    *s.top++ = e;
}

void Pop(SqStack &s)
{
    if (s.top == s.base)
    {
        exit(-2);
    }
    s.top--;
}

int getTop(SqStack s)
{
    if (s.base == s.top)
    {
        return -1;
    }
    return *--s.top;
}

int main()
{
    SqStack s;
    int n,c;
    cin>>n;
    Init_stack(s,n);

    for (int i = 0; i < n; ++i)
    {
        cin>>c;
        Push(s,c);
    }
    int k;
    cin>>k;

    for (int i = 0; i < k; ++i)
    {
        Pop(s);
    }

    int t = getTop(s);
    cout<<t;
    return 0;
}