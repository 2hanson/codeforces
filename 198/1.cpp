#include <iostream>
using namespace std;

long long getGcd(long long x, long long y) {
    long long tmp;
    while (y) {
        tmp = x % y;
        x = y;
        y = tmp;
    }
    return x;
}

long long getLcm(long long x, long long y) {
    return x*y/getGcd(x, y);
}

int main()
{
    long long x, y, a, b;
    cin>>x>>y>>a>>b;
    long long lcm = getLcm(x, y);
    long long ans;
    ans = b/lcm-(a-1)/lcm;
    cout<<ans<<endl;
}
