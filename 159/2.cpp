#include <iostream>
using namespace std;

int main()
{
    long m, n;
    cin>>n>>m;
    long t;
    if (n > m)
    {
        t = n;
        n = m;
        m = t;
    }
    int ansp = 0, ansv = 0;

    if (m-n>=1)
    {
        ansp += (m-n);
    }

    ansv = n;
    ansp += (n-1);

    cout<<ansp<<" "<<ansv<<endl;
    return 0;
}

