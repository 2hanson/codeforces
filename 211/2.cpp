#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long opt = -1, tmp = 0;
    long ans = 0;
    long n, k;
    cin>>n>>k;
    vector<int> fence(n, 0);
    for (int i = 0; i < n; ++i) {
        cin>>fence[i];
    }
    int fi;
    for (fi = 0; fi < k; ++fi) {
        tmp += fence[fi];
    }
    opt = tmp;
    ans = 0;
    int si = 0;
    for (; fi < n; ++fi) {
        tmp -= fence[si++];
        tmp += fence[fi];
        if (tmp < opt) {
            opt = tmp;
            ans = si;
        }
    }
    cout<<ans+1<<endl;
    return 0;
}
