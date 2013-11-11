#include <iostream>
#include <vector>
using namespace std;

//binary search the number of bikes can rent.
bool check(long k, long ttl, const vector<long> &boys, const vector<long> &bikes) {
    //the richest k boys rent the cheapest k bikes
    int i, diff = 0;
    for (i = 0; i < k && ttl >= 0; ++i) {
        diff = boys[boys.size() - k + i] - bikes[i];
        if (diff < 0) {
            ttl += diff;
        }
    }
    return i == k;
}

long getS(long k, long ttl, const vector<long> &boys, const vector<long> &bikes) {
    //the richest k boys rent the cheapest k bikes
    //boys: (boys.size() - k, boys.size()-1)
    //bikes: (0, k-1)
    int i, diff = 0;
    long p = 0;
    for (i = 0; i < k; ++i) {
        diff = boys[boys.size()-k + i] - bikes[i];
        if (diff < 0) {
            ttl += diff;
        }
        p += boys[boys.size() - k + i];
    }
    for (int i = 0; i < k && ttl > 0; ++i) {
        if (ttl >= boys[boys.size()-k+1]) {
            ttl -= boys[boys.size()-k+1];
            p -= boys[ boys.size()-k+1 ];
        }
        else {
            p -= ttl;
            ttl -= boys[boys.size()-k+1];
        }
    }
    return p<0 ? 0 : p;
}

int main()
{
    long n, m, a;
    cin>>n>>m>>a;
    vector<long> boys(n, 0);
    for (long i = 0; i < n; ++i) {
        cin>>boys[i];
    }
    vector<long> bikes(m, 0);
    for (long i = 0; i < m; ++i) {
        cin>>bikes[i];
    }
    sort(boys.begin(), boys.end());
    sort(bikes.begin(), bikes.end());
    long r = 0, s = 0;
    long mid, low = 0, high = min(n, m) - 1;
    while (low <= high) {
        mid = low + (high - low)/2;
        if (check(mid, a, boys, bikes)) {
            if (mid > r) {
                r = mid;
                s = getS(mid, a, boys, bikes);
            }
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout<<r+1<<" "<<s<<endl;
    return 0;
}
