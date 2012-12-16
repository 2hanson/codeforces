#include <iostream>
using namespace std;

const long maxn = 4005;
long b[maxn];
long n;
long dp[maxn][2] = {0};//dp[][0] is len, dp[][1] is q

int main()
{
    cin>>n;
    cin>>b[1];
    dp[1][0] = 1;

    for (long i = 2; i <= n; ++i)
    {
        cin>>b[i];
        dp[i][0] = 1;

        long temp = dp[1][0];
        dp[i][1] = b[1] - b[i];

        for (long k = 2; k < i; ++k)
        {   
            long tdp = (b[i]-b[k]);
            if (dp[k][0] % 2 != 0)
            {
                tdp = -tdp;
            }

            if (dp[k][1] == tdp && dp[k][0]>temp)
            {
                temp = dp[k][0];
                dp[i][1] = tdp;
            }
        }

        dp[i][0] += temp;
    }

    long ans = 0;
    for (long i = 1; i <= n; ++i)
    {
        if (dp[i][0] > ans)
        {
            ans = dp[i][0];
        }
    }
    cout<<ans<<endl;
}

