#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    long long x, y;
    cin>>x>>y;
    long long ans = abs(x) + abs(y);
    if (x < 0) {
        cout<<-ans<<" "<<0<<" "<<0<<" "<<(y>0?ans:-ans)<<endl;
    }
    else {
        cout<<0<<" "<<(y>0?ans:-ans)<<" "<<ans<<" "<<0<<endl;
    }
    return 0;
}
