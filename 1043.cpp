
#include <stdio.h>
int main()
{
    int team[1000],tot=-1;
    char c;
    while(scanf("%c",&c))
    {
        if(c=='#') break;
        else if(c==' ') continue;
        else if(c<='9'&&c>='0')team[++tot]=c-'0';
        else{
            if(c=='+') team[tot-1]=team[tot]+team[tot-1];
            if(c=='*') team[tot-1]=team[tot]*team[tot-1];
            if(c=='-') team[tot-1]=team[tot-1]-team[tot];
            if(c=='/') team[tot-1]=team[tot-1]/team[tot];
            tot--;
        }
    }
    printf("%d",team[tot]);
    return 0;
}


