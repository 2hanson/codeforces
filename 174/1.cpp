#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#define LL long long
using namespace std;
long p;
long ans;
long pre;

void pfactor(int input)
{
    pre = -1;
    for (int d = 2; d <= input; ++d)
    {
        if (input % d == 0)
        {
            input /= d;
            if (pre != d)
                ans = ans*(d-1)/d;
            pre = d;
            if (input == 1)
                break;
            --d;
        }
    }
}

int main()
{
    cin>>p;
    --p;
    ans = p;
    pfactor(p);
    cout<<ans<<endl;
    return 0;
}

