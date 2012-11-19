#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ta = 0;
    int a = 0;
    int tb = 0;
    int b = 0;
    int t, x, y;
    while (n--)
    {
        cin>>t>>x>>y;
        if (t == 1)
        {
            ta += 10;
            a += x;
        }
        else
        {
            tb += 10;
            b+=x;
        }
    }

    if (2*a >= ta)
    {
        cout<<"LIVE"<<endl;
    }
    else
    {
        cout<<"DEAD"<<endl;
    }
    if (2*b >= tb)
    {
        cout<<"LIVE"<<endl;
    }
    else
    {
        cout<<"DEAD"<<endl;
    }
    return 0;
}

