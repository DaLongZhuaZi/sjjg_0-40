#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int *data, n, x;
    cin>>n;

    data = (int*)malloc(n*sizeof(int));

    for (int i = 0; i < n; ++i)
    {
        cin>>data[i];
    }

    cin>>x;
    if (x<0 || x > n)
    {
        cout<<"error!";
        return 0;
    }

    for (int i = x; i <n; ++i)
    {
        cout<<data[i]<<" ";
    }

    for (int i = 0; i < x; ++i)
    {
        cout<<data[i]<<" ";
    }

    return 0;
}