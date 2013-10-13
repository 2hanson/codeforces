#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int n, l, r, ql, qr;
    cin>>n>>l>>r>>ql>>qr;
    vector<int> nums(n+1, 0);
    vector<int> l1(n+1, 0);
    vector<int> r1(n+1, 0);
    vector<int> l2(n+1, 0);
    vector<int> r2(n+1, 0);
    
    for (int i = 1; i <= n; ++i) {
        cin>>nums[i];
    }
    vector<int> dpl(n+1, 0);
    vector<int> dpr(n+1, 0);
    dpl[1] = l*nums[1];
    l1[1] = 2, r1[1] = n;
    dpr[1] = r*nums[n];
    l2[1] = 1, r2[1] = n-1; 
    int t1, t2;
    for (int i = 2; i <= n; ++i) {
        t1 = dpr[i-1] + l*nums[l2[i-1]];
        t2 = dpl[i-1] + ql + l*nums[l1[i-1]];
        if (t1 < t2) {
            dpl[i] = t1;
            l1[i] = l2[i-1] + 1;
        }
        else {
            dpl[i] = t2;
            l1[i] = l1[i-1] + 1;
        }
        t1 = dpl[i-1] + r * nums[ r1[i-1] ];
        t2 = dpr[i-1] + qr + r * nums[ r2[i-1] ];
        if (t1 < t2) {
            dpr[i] = t1;
            r2[i] = r1[i-1] - 1;
        }
        else {
            dpr[i] = t2;
            r2[i] = r2[i-1] - 1;
        }
    }
    cout<<min(dpl[n], dpr[n])<<endl;
    return 0;
}

