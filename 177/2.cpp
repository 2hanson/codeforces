#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#define LL long long

using namespace std;
const int maxn = 105;
long a[maxn][maxn];
long dp[maxn][maxn];
long n, m, d;
long ans;

long cal(int tr)
{
    long tmp = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (ans!=-1 && tmp>ans)
            {
                return -1;
            }
            long diff = abs(a[i][j] - tr);
            if (diff%d != 0)
            {
                return -1;
            }
            else
            {
                tmp += (diff/d);
            }
        }
    }
    return tmp;
}

int main()
{
    long sum = 0;
    cin>>n>>m>>d;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin>>a[i][j];
            sum += a[i][j];
        }
    }
/*
    long ave = sum / (n*m);
    long sel = a[0][0];
    long diff = abs(a[0][0] - ave); 
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (diff > abs(a[i][j]-ave))
            {
                sel = a[i][j];
                diff = abs(a[i][j] - ave);
            }
        }
    }
    ans = -1;
    ans = cal(sel);
  */ 
    ans = -1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            long tmp = cal(a[i][j]);
            if (tmp == -1)
            {
                continue;
            }
            else
            {
                if (ans == -1)
                {
                    ans = tmp;
                }
                else if (ans > tmp)
                {
                    ans = tmp;
                }
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}

