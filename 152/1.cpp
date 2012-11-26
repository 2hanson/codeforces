#include <iostream>
using namespace std;

int main()
{
    long n;
    long left = 0;
    long right = 0;
    int ld, rd;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>ld>>rd;
        left += ld;
        right += rd;
    }
    
    long ans = 0;
    if (2*left <= n)
    {
        ans += left;
    }
    else
    {
        ans += (n - left);
    }
    if (2*right <= n)
    {
        ans += right;
    }
    else
    {
        ans += (n-right);
    }

    cout<<ans<<endl;

    return 0;
}

