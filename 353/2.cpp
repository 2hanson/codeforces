#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    n = n*2;
    vector<int> ret(n, 0);
    vector<int> ra(100, 0);
    vector<int> rb(100, 0);
    for (int i = 0; i < 100; ++i) {
        ra[i] = 0;
        rb[i] = 0;
    }
    int tmp;
    for (int i = 0; i < n; ++i) {
        cin>>tmp;
        if (ra[0] <= rb[0]) {
            if (ra[tmp] == 0) {
                ra[tmp] = 1;
                ret[ i ] = 1;
                ++ra[0];
            }
            else if (rb[tmp] == 0) {
                rb[tmp] = 1;
                ret[ i ] = 2;
                ++rb[0];
            }
            else {
                ret[ i ] = -1;
            }
        }
        else {
            if (rb[tmp] == 0) {
                rb[tmp] = 1;
                ret[ i ] = 2;
                ++rb[0];
            }
            else if (ra[tmp] == 0) {
                ra[tmp] = 1;
                ret[ i ] = 1;
                ++ra[0];
            }
            else {
                ret[ i ] = -1;
            }
        }
    }
    cout<<ra[0]*rb[0]<<endl;
    for (int i = 0; i < n; ++i) {
        if (ret[i] != -1) {
            continue;
        }
        if (ra[0] <= rb[0]) {
            ret[i] = 1;
            ++ra[0];
        }
        else {
            ret[i] = 2;
            ++rb[0];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            cout<<" ";
        }
        cout<<ret[i];
    }
    cout<<endl;
    return 0;
}

