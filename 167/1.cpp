#include <iostream>
using namespace std;

const int maxn = 105;

int main()
{
    int n;
    cin>>n;
    int temp;
    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        cin>>temp;
        res += temp;
    }

    ++n;
    int ans = 0;
    for (int i = 0; i < 5; ++i)
    {
        if ((res+i) % n != 0)
        {
            ++ans;
        }
    }

    cout<<ans<<endl;
    
    return 0;
}

