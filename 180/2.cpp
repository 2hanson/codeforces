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
        long t, sx, sy, ex, ey;
        string wind;
        long dx;
        long dy;
        int ans;
    public:
        int getsecond()
        {
            return ans;
        }

        bool isok()
        {
            return dx==ex && dy==ey;
        }

        bool canwork(int tx, int ty)
        {
            return (abs(ex-dx)+abs(ey-dy)) > (abs(ex-(dx+tx))+abs(ey-(dy+ty)));
        }

        void solve()
        {
            int i = 0;
            for (i = 0; i<t && !isok(); ++i)
            {
                if (wind[i] == 'E')
                {
                    if (!canwork(1, 0))
                    {
                        continue;
                    }
                    ++dx;
                }
                else if (wind[i] == 'S')
                {
                    if (!canwork(0, -1))
                    {
                        continue;
                    }
                    --dy;
                }
                else if (wind[i] == 'W')
                {
                    if (!canwork(-1, 0))
                    {
                        continue;
                    }
                    --dx;
                }
                else if (wind[i] == 'N')
                {
                    if (!canwork(0, 1))
                    {
                        continue;
                    }
                    ++dy;
                }
            }

            if (isok())
            {
                ans = i;
            }
        }

        void read()
        {
            cin>>t>>sx>>sy>>ex>>ey;
            cin>>wind;
            dx = sx;
            dy = sy;
            ans = -1;
        }

};

int main()
{
    Solution *sl = new Solution();
    sl->read();
    sl->solve();
    cout<<sl->getsecond()<<endl;

    return 0;
}

