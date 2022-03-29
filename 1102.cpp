#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int *data, n;
    cin>>n;

    data = (int*)malloc(n*sizeof(int));

    for (int i = 0; i < n; ++i)
    {
        cin>>data[i];
    }

    for (int i = n-1; i >= 0; --i)
    {
        if (data[i] <= data[0])
        {
            cout<<data[i]<<" ";
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (data[i]>data[0])
        {
            cout<<data[i]<<" ";
        }
    }
    return 0;
}