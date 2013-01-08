#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> sockets;
int n, m, k, t;

int main()
{
    cin>>n>>m>>k;
    for (int i = 0; i < n; ++i)
    {
        cin>>t;
        sockets.push_back(t);
    }
    sort(sockets.begin(), sockets.end());
    t = k;
    int ans = 0;
    for (int i = sockets.size()-1; t < m && t>= 1 && i >= 0; --i)
    {
        int diff = sockets[i]-1;
        if (diff <= 0)
        {
            break;
        }
        ++ans;
        t += diff;
    }

    if (t<m)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<ans<<endl;
    }
    return 0;
}

