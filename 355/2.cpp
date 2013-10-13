#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int c1, c2, c3, c4;
    cin>>c1>>c2>>c3>>c4;
    int n, m;
    cin>>n>>m;
    vector<int> buses(n+1, 0);
    vector<int> tro(m+1, 0);
    for (int i = 1; i <= n; ++i) {
        cin>>buses[i];
        if (buses[i]*c1 > c2) {
            buses[i] = c2;
        }
        else {
            buses[i] *= c1;
        }
        buses[0] += buses[i];
    }

    if (buses[0] > c3) {
        buses[0] = c3;
    }

    for (int i = 1; i <= m; ++i) {
        cin>>tro[i];
        if (tro[i]*c1 > c2) {
            tro[i] = c2;
        }
        else {
            tro[i] *= c1;
        }
        tro[0] += tro[i];
    }
    if (tro[0] > c3) {
        tro[0] = c3;
    }
    int ans = c4;
    if (ans > tro[0] + buses[0]) {
        ans = tro[0] + buses[0];
    }
    cout<<ans<<endl;
    return 0;
}
