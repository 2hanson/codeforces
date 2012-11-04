#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long y, k, n;
    cin>>y>>k>>n;
    long long x;
    bool first = true;

    if (k < y)
    {
        x = k - y%k;
        while ((x+y) <= n)
        {
            if (first == true)
            {
                cout<<x;
                first = false;
            }
            else
            {
                cout<<" "<<x;
            }
            x += k;
        }
    }
    else if (k == y)
    {
        x = k;
        while ((x+y) <= n)
        {
            if (first == true)
            {
                cout<<x;
                first = false;
            }
            else
            {
                cout<<" "<<x;
            }
            x += k;
        }
    }
    else if (k > y)
    {
        x = k - y;

        while ((x+y) <= n)
        {
            if (first == true)
            {
                cout<<x;
                first = false;
            }
            else
            {
                cout<<" "<<x;
            }
            x+=k;
        }
    }

    if (first == true)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        cout<<endl;
    }
    return 0;
}
