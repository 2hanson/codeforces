#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#define LL long long
using namespace std;
int main()
{
    long n;
    int t;
    long k;
    long add;
    cin>>n;
    long *toleft = (long*)malloc((200005)*sizeof(long));
    vector<long> seqs;
    seqs.push_back(0);
    double ans = 0;
    LL sum = 0;
    memset(toleft, 0, sizeof(toleft));
    while (n--)
    {
        cin>>t;
        if (t == 1)
        {
            cin>>k>>add;
            toleft[k-1] += add;
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
            int ttt = seqs.size();
            seqs[ttt-1] += toleft[ttt-1];
            toleft[ttt-2] += toleft[ttt-1];
            toleft[ttt-1] = 0;
            sum -= seqs[ ttt-1 ];
            seqs.pop_back();
        }

        printf("%.6lf\n", sum*1.0/seqs.size());
    }

    return 0;
}

