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

class Solution
{
    private:
        long n, m, k;
        vector<long> fa;
        vector<long> fb;
        bool flag;
    public:
        void read()
        {
            fa.clear();
            fb.clear();
            long tmp;
            scanf("%ld %ld %ld", &n, &m, &k);
            for (int i = 0; i < n; ++i)
            {
                scanf("%ld", &tmp);
                fa.push_back(tmp);
            }
            sort(fa.begin(), fa.end());
            for (int i = 0; i < m; ++i)
            {
                scanf("%ld", &tmp);
                fb.push_back(tmp);
            }
            sort(fb.begin(), fb.end());
        }

        void solve()
        {
            flag = false;
            int pa = 0;
            for (int i = 0; i < m; ++i)
            {
                if (fb[i] >= fa[pa])
                {
                    ++pa;
                    if (pa == n)
                    {
                        flag = true;
                        break;
                    }
                }
            }

            if (flag == false)
            {
                if (fa[fa.size()-1] <= fb[0])
                {
                    flag = true;
                }
            }
        }

        void output()
        {
            if (flag == true)
            {
                printf("NO\n");
            }
            else
            {
                printf("YES\n");
            }
        }
};

int main()
{
    Solution *sl = new Solution();
    sl->read();
    sl->solve();
    sl->output();

    return 0;
}

