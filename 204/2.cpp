#include <vector>
#include <iostream>
using namespace std;

const int maxn = 100005;

int main()
{
    int n;
    int rec[maxn];
    int pos[maxn];
    cin>>n;
    for (int i = 1; i <= 100000; ++i) {
        rec[i] = 0;
        pos[i] = -1;
    }
    int t;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin>>t;
        if (pos[t] == -1) {
            ++ans;
        }
        else if (rec[t] == 0) {
            rec[t] = i - pos[t];
        }
        else if (i-pos[t] != rec[t]) {
            if (rec[t] != -1) {
                --ans;
            }
            rec[t] = -1;
        }
        pos[t] = i;
    }
    cout<<ans<<endl;
    for (int i = 1; i <= 100000; ++i) {
        if (pos[i] == -1 || rec[i] == -1) {
            continue;
        }
        cout<<i<<" "<<rec[i]<<endl;
    }
    return 0;
}

