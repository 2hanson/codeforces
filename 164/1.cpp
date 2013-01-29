#include <iostream>
using namespace std;

const int maxn = 105;

int team[maxn][2];

int main()
{
    int n;
    cin>>n;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        cin>>team[i][0]>>team[i][1];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int k = 0; k < n; ++k)
        {
            if (team[i][0] == team[k][1])
            {
                ++ans;
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}

