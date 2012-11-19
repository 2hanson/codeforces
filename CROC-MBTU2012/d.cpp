#include <iostream>
using namespace std;

const int maxn = 105;
long b[maxn][maxn];

int main()
{
    int n;
    cin>>n;
    long k;
    if (n == 1)
    {
        cin>>k;
        cout<<0<<endl;
    }
    else
    {
        for (int index = 1; index <= n; ++index)
        {
            long ans = 0;
            for (int j = 1; j <= n; ++j)
            {
                cin>>k;
                if (k == -1)
                    continue;

                ans |= k;
            }
            if (index == 1)
            {
                cout<<ans;
            }
            else
            {
                cout<<" "<<ans;
            }
        }

        cout<<endl;
    }
    return 0;
}
