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
        int n;
        int L[2];
        int R[2];
        string walk;
    public:
        int s, t;
        void read()
        {
            cin>>n>>walk;
            L[0] = L[1] = R[0] = R[1] = -1;
        }

        void solve()
        {
            for (int i = 0; i < n; ++i)
            {
                if (walk[i] == 'R')
                {
                    if (R[0] == -1)
                    {
                        R[0] = R[1] = i + 1;
                    }
                    else
                    {
                        R[1] = i + 1;
                    }
                }
                if (walk[i] == 'L')
                {
                    if (L[0] == -1)
                    {
                        L[0] = L[1] = i + 1;
                    }
                    else
                    {
                        L[1] = i + 1;
                    }
                }
            }
        
            if (R[0] != -1)
            {
                s = R[0];
                if (L[0] == -1)
                {
                    t = R[1] + 1;
                }
                else
                {
                    t = R[1];
                }
            }
            else
            {
                s = L[1];
                t = L[0]-1;
            }
        }
};
int main()
{
    Solution *sl = new Solution();
    sl->read();
    sl->solve();
    cout<<sl->s<<" "<<sl->t<<endl;
}

