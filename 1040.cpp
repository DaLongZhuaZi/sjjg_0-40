
#include "iostream"
#include "stdio.h"
using namespace std;
typedef int ElemType;
  
typedef struct Node
{
    ElemType i; // 指数
    ElemType c; // 系数
    Node *next;
}*pNode;
  
void Creat(pNode &L)
{
    int i, c;
    scanf("%d,%d", &c, &i);
    //  cin >> c >> "," >> i;
    if(i == 0 && c == 0) L = NULL;
    else
    {
        L = new Node;
        L->c = c;
        L->i = i;
        Creat(L->next);
    }
}
  
void Add(pNode &L1, pNode L2)
{
    pNode p = L1->next, q = L2->next;
    pNode r = L1, s = NULL;
      
    while (p || q)
    {
        if(p == NULL)
        {
            s = q->next;
            q->next = r->next;
            r->next = q;
            q = s;
        }
        else if(q == NULL)
        {
            p = p->next;
            r = r->next;
        }
        else if (p->i > q->i)
        {
            s = q->next;
            q->next = r->next;
            r->next = q;
            q = s;
            r = r->next;
        }
        else if (p->i == q->i)
        {
            p->c += q->c;
            s = p->next;
            if(p->c == 0)
            {
                  
                r->next = p->next;
                delete p;
                  
            }
            r = r->next;
            p = s;
            q = q->next;
        }
        else
        {
            p = p->next;
            r = r->next;
        }
    }   
}
int main()
{
    pNode L1, L2;
    L1 = new Node;
    L2 = new Node;
    Creat(L1->next);
    Creat(L2->next);
    Add(L1,L2);
    while (L1->next)
    {
        cout << L1->next->c << "x^"
            << L1->next->i;
        L1 = L1->next;
        if(L1->next) cout << "+";
    }
}