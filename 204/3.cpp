#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

bool cmp(double a, double b) {
    int ta = (int)a, tb = (int)b;
    return abs(a - (double)ta) < abs(b - (double)tb);
}

int main()
{
    int n;
    cin>>n;
    int ttl = 2*n;
    vector<double> pres(ttl, 0);
    for (int i = 0; i < ttl; ++i) {
        cin>>pres[i];
    }
    int left = 0, right = ttl - 1;//
    for (int i = 0; i <= right; ++i) {
        int tv = (int) pres[i];
        if (double(tv) == pres[i]) {
            continue;
        }
        double diff = pres[i] - double(tv);
        if (diff < 0.5 ) {
            swap(pres[left++], pres[i]);
        }
        else if (diff > 0.5) {
            swap(pres[right--], pres[i]);
        }
    }
    //sort(pres.begin(), pres.end(), cmp);
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        int tv = (int)pres[ ttl - 1 - i ];
        if (double(tv) != pres[ttl - 1 - i]) {
            ++tv;
        }
        ans += ( pres[i] + pres[ ttl - 1 - i ] - (int)pres[i] - tv); 
    }
    ans = abs(ans);
    printf("%.3lf\n", ans);
    return 0;
}

