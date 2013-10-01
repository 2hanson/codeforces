#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    int amin = -1, amax = -1, a;
    while (n--) {
        cin>>a;
        if (amin == -1 || amin > a) {
            amin = a;
        }
        if (amax == -1 || amax < a) {
            amax = a;
        }
    }
    int b, bmin = -1;
    while (m--) {
        cin>>b;
        if(bmin == -1 || bmin > b) {
            bmin = b;
        }
    }
    int ans = 2*amin;
    while (ans < amax && ans < bmin) {
        ++ans;
    }
    if (ans >= bmin) {
        ans = -1;
    }
    cout<<ans<<endl;
    return 0;
}

