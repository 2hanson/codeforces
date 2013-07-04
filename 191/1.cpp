#include <iostream>
using namespace std;

int main()
{
    int n;
    int ans = 0;
    cin>>n;
    if (n == 0) {
        cout<<0<<endl;
        return 0;
    }
    int num[105];
    for (int i = 0; i < n; ++i) {
        cin>>num[i];
        ans += num[i];
        num[i] = 1-2*num[i];
    }
    int tmp = num[0], opt = num[0];
    for (int i = 1; i < n; ++i) {
        if (tmp < 0) {
            tmp = 0;
        }
        tmp += num[i];
        if (tmp > opt) {
            opt = tmp;
        }
    }
    cout<<ans+opt<<endl;
    return 0;
}

