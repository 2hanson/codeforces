#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cctype>
#include <map>
#include <iomanip>
#include <set>
                   
using namespace std;
                   
#define eps 1e-8
#define pi acos(-1.0)
#define inf 1<<30
#define linf 1LL<<60
#define pb push_back
#define lc(x) (x << 1)
#define rc(x) (x << 1 | 1)
#define lowbit(x) (x & (-x))
#define ll long long

int n, k, a[100010];
set<ll> vis;
int main() {
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    sort(a, a+n);
    int ans = 0;
    for (int i=0; i<n; i++) {
        if (vis.find(a[i]) == vis.end()) {
            ans++;
            vis.insert((1ll*a[i]*k));
        }
    }

    printf("%d\n", ans);
    return 0;
}
