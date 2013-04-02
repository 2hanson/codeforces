#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

#define LL long long
using namespace std;

int main()
{
    long n, k;
    cin>>n>>k;
    long tol = 0;
    long L, R;
    for (int i = 0; i < n; ++i)
    {
        cin>>L>>R;
        tol += (R - L + 1);
    }

    tol = tol % k;
    if (tol == 0)
    {
        cout<<tol<<endl;
    }
    else
    {
        cout<<k-tol<<endl;
    }

    return 0;
}

