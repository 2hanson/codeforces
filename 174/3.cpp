#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#define LL long long
using namespace std;

int main()
{
    long n;
    int t;
    long k;
    long add;
    cin>>n;
    vector<long> seqs;
    seqs.push_back(0);
    double ans = 0;
    LL sum = 0;
    while (n--)
    {
        cin>>t;
        if (t == 1)
        {
            cin>>k>>add;
            for (int i = 0; i < k; ++i)
            {
                seqs[i] += add;
            }
            sum += (k*add);
        }
        else if (t== 2)
        {
            cin>>k;
            sum += k;
            seqs.push_back(k);
        }
        else
        {
            sum -= seqs[ seqs.size()-1 ];
            seqs.pop_back();
        }

        printf("%.6f\n", sum*1.0/seqs.size());
    }

    return 0;
}

