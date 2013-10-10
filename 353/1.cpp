#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    bool flag = false;
    vector<int> a(n+1, 0);
    vector<int> b(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        cin>>a[i]>>b[i];
        if ((a[i]&1) ^ (b[i]&1)) {
            flag = true;
        }
        a[0] += a[i];
        b[0] += b[i];
    }
    if (!(a[0]&1) && !(b[0]&1)) {
        cout<<0<<endl;
    }
    else if (!(a[0]&1) ^ !(b[0]&1)) {
        cout<<-1<<endl;
    }
    else {
        cout<<(flag?1:-1)<<endl;
    }

    return 0;
}

