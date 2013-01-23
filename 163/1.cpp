#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string st;
    cin>>st;
    int dp[100];
    for (int i = 0; i < n; ++i)
    {
        dp[i] = 1;
    }

    for (int i = 0; i < n; ++i)
    {
        //dp[i]
        for (int k = 0; k < i; ++k)
        {
            if (st[k] != st[i])
            {
                if ((dp[k]+1) > dp[i])
                {
                    dp[i] = dp[k] + 1;
                }
            }
        }
    }

    cout<<n-dp[n-1]<<endl;
    return 0;
}

