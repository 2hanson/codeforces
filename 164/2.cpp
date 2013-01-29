#include <iostream>
#define LL long long
using namespace std;

int main()
{
    int n;
    LL ans = 0;

    cin>>n;
    for (int k = n; k >= 1; --k)
    {
        ans = ans + (k-1 + (k-1)*(n-k) + 1);
    }

    cout<<ans<<endl;

    return 0;
}

