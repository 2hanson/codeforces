#include <iostream>
using namespace std;

const int maxn = 1005;
int d[maxn];
int s[maxn];

int main()
{
    int m, k;

    cin>>m>>k;

    for (int index = 1; index <= m; ++index)
    {
        cin>>d[index];
    }

    for (int index = 0; index < m; ++index)
    {
        cin>>s[index];
    }

    int ans = 0;
    int fuel = 0;
    int maxS = 0;
    for (int index = 1; index <= m; ++index)
    {
        fuel += s[index - 1];
        if (s[index - 1] > maxS)
            maxS = s[index - 1];
        while (fuel < d[index])
        {
            ans += k;
            fuel += maxS;
        }

        fuel -= d[index];
        ans += d[index];
    }

    cout<<ans<<endl;

    return 0;
}

