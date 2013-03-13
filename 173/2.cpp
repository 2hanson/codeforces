#include <algorithm>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
using namespace std;

const int maxn = 1000006;
long total;
int a[maxn];
int tmp[maxn];
int rec[maxn];
bool flag;
int n;

void dfs(int cur, long sum)
{
    if (cur >= n)
    {
        return;
    }
    if (flag == true)
    {
        return;
    }
    if (sum>=total-250 && sum<=total+250)
    {
        flag = true;
        return;
    }

    for (int i = cur; i < n; ++i)
    {
        if (sum+a[i] > total+250)
        {
            return;
        }
        rec[i] = 1;
        dfs(i+1, sum+a[i]);
        if (flag == true)
        {
            return;
        }
        rec[i] = 0;
    }
}

int main()
{
    total = 0;
    
    scanf("%d", &n);
    total = n*1000/2;
    int k;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d", &a[i], &k);
        tmp[i] = a[i];
        rec[i] = 0;
    }
    sort(tmp, tmp+n);
    
    flag = false;
    dfs(0, 0);

    if (flag == false)
    {
        printf("-1\n");
        return 0;
    }

    return 0;
}

