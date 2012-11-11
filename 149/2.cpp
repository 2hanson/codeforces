#include <iostream>
using namespace std;

int main()
{
    long n;
    long ans = -1;
    long l, r;
    long sl, sr;
    long tl, tr;
    cin>>n;
    cin>>l>>r;
    tl = sl = l;
    tr = sr = r;
    long tans = 1;
    bool flag = true;
    for (long index = 2; index <= n; ++index)
    {
        cin>>l>>r;
        if (l < sl)
        {
            sl = l;
        }
        if (r > sr)
        {
            sr = r;
        }

        if (l <= tl && r >= tr)
        {
            tans = index;
            tl = l;
            tr = r;
        }

        if (tl <= sl && tr >= sr)
        {
            flag = true;
        }
        else
        {
            flag = false;
        }
    }

    if (flag == true)
    {
        cout<<tans<<endl;
    }
    else
    {
        cout<<"-1"<<endl;
    }
    return 0;    
}
