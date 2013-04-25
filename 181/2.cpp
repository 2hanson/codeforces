#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <ctime>
#include <list>
#include <iomanip>

using namespace std;
#define LL long long
#define DEBUG(x) cout<< #x << ":" << x <<endl
#define PII pair<int, int>
#define MP make_pair
//~x + 1, 负数补码
#define lowbit(x) (x&(-x))
#define INF (1<<30)
/*
 * int cmp(const Cs *a, const Cs *b)
 * {
 *      return a->v < b->v;
 * }
 *
 *sort(vec.begin(), vec.end(), cmp);
 * */
const int maxn = 50;
int n, m;
int g[maxn];
int cnt[maxn];
vector<vector<int> >res;

bool dfs(int cur, vector<int> tmp)
{
    for (int i = cur; i <= n; ++i)
    {
        if (g[i] == cur)
        {
            tmp.push_back(i);
        }
    }

    g[cur] = -1;

    if (tmp.size() == 3)
    {
        res.push_back(tmp);
        return true;
    }

    for (int i = cur + 1; i <= n; ++i)
    {
        if (g[i] != i)
        {
            continue;
        }

        if (cnt[i]+tmp.size() > 3)
        {
            continue;
        }

        if (dfs(i, tmp) == true)
        {
            return true;
        }
    }

    g[cur] = cur;
    for (int i = cur; i <= n; ++i)
    {
        if (g[i] == cur)
        {
            tmp.pop_back();
        }
    }

    return false;
}

int main()
{
    cin>>n>>m;
    for (int i = 1; i <= n; ++i)
    {
        cnt[i] = 1;
        g[i] = i;
    }

    bool flag = true;
    int ai, bi;
    while (m--)
    {
        cin>>ai>>bi;
        if (ai > bi)
        {
            swap(ai, bi);
        }

        if (g[bi] == g[ai])
        {
            continue;
        }

        for (int i = 1; i <= n; ++i)
        {
            if (g[i] == g[bi])
            {
                g[i] = g[ai];
                ++cnt[ g[ai] ];
                if (cnt[ g[ai] ]> 3)
                {
                    flag = false;
                }
            }
        }

    }

    if (flag == false)
    {
        cout<<-1<<endl;
    }
    else
    {
        res.clear();
        vector<int> tmp;
        int rec = 0;
        for (int i = 1; i<=n && flag==true; ++i)
        {
            if (g[i] == i)
            {
                tmp.clear();
                flag = dfs(i, tmp);
            }
        }

        if (flag == false)
        {
            cout<<-1<<endl;
        }
        else
        {
            for (int i = 0; i < res.size(); ++i)
            {
                for (int k = 0; k < res[i].size(); ++k)
                {
                    if (k > 0)
                    {
                        cout<<" ";
                    }
                    cout<<res[i][k];
                }
                cout<<endl;
            }
        }
    }

    return 0;
}

