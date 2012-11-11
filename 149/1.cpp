#include <iostream>

using namespace std;

int main()
{
    int x, y, a, b;
    cin>>x>>y>>a>>b;
    int ans = 0;
    for (int i = a; i <= x; ++i)
    {
        for (int j = b; j < i && j <= y; ++j)
        {
            ++ans;
        }
    }
    
    cout<<ans<<endl;
    for (int i = a; i <= x; ++i)
    {
        for (int j = b; j < i && j <= y; ++j)
        {
            cout<<i<<" "<<j<<endl;
        }
    }
    
    return 0;
}

