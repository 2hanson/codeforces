#include <iostream>
using namespace std;


int main()
{
    int n,k;
    cin>>n>>k;
    int ans = 0;
    long a;
    while (n--)
    {
        int rec = 0;
        cin>>a;
        while (a>0 && rec<=k)
        {
            int temp = a % 10;
            a = a / 10;
            if (temp == 4 || temp == 7)
            {
                ++rec;
            }
        }
        if (rec <= k)
        {
            ++ans;
        }
    }

    cout<<ans<<endl;
    return 0;
}

