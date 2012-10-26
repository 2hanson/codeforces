#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int k;
    int n;
    cin>>n;
    k = n;
    int h, m, preh, prem;

    int ans = -1;
    int temp = 0;
    while (k--)
    {
        cin>>h>>m;
        if (k == n-1)
        {
            ++temp;
        }
        else if (preh == h && prem == m)
        {
            ++temp;
        }
        else
        {
            if (temp > ans)
            {
                ans = temp;
            }

            temp = 1;
        }

        preh = h;
        prem = m;
    }

    if (ans < temp)
        ans = temp;
    cout<<ans<<endl;
}
