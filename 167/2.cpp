#include <iostream>
#define LL long long
using namespace std;

const long maxn = 100005;
long n;
LL temp[maxn];
LL rec[maxn];
int main()
{
    long ni;
    cin>>n;
    for (int i = 0; i <= n; ++i)
    {
        temp[i] = 0;
    }

    for (int i = 1; i <= n; ++i)
    {
        cin>>ni;  
            
        while (ni % 2 == 0)
        {
            ni = ni>>1;
        }
            
        long ti = 0;
        while (ni!=1 && ni!=0)
        {
            ni = ni>>1;
            ++ti;
            while (ni % 2 == 0)
            {
                ni = ni>>1;
            }
        }

        rec[i] = temp[ti];
        ++temp[ti];
    }

    LL ans = 0;
    for (int i = 0; i <= n; ++i)
    {
        ans += rec[i];
    }

    cout<<ans<<endl;
    return 0;
}

