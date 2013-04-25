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

const long MOD = 1000000007;


LL fast(LL a,LL b,LL p)
{
    LL s=1;
    while(b)
    {
        if(b&1) s=(s*a)%p;
        b=b>>1;
        a=(a*a)%p;
    }
    return s;
}

LL cal(LL a,LL b,LL p)
{
    if(a<b) return 0;
    if(b>a-b) b=a-b;
    LL ans=1,coma=1,comb=1;
    for(LL i=0;i<b;i++)
        coma=(coma*(a-i))%p,comb=(comb*(b-i))%p;
    coma=coma*fast(comb,p-2,p);
    return coma%p;
}

LL Lucas(LL a,LL b,LL p)
{
    LL ans=1;
    while(a&&b&&ans)
    {
        ans=ans*cal(a%p,b%p,p);
        a=a/p;
        b=b/p;
    }
    return ans;
}

LL ta, tb, tn;
LL tans;

bool isb(long num)
{
    while (num)
    {
        int tmp = num % 10;
        if (tmp!=ta && tmp!=tb)
        {
            return false;
        }

        num /= 10;
    }

    return true;
}

void solve()
{
    for (long i = 0; i <= tn; ++i)
    {
        long tmp = 0;
        tmp = i * ta + (tn-i) * tb;
        if (isb(tmp) == false)
        {
            continue;
        }
        tans += Lucas(tn, i, MOD);
        tans = tans % MOD;
    }
}

int main()
{
    cin>>ta>>tb>>tn;
    tans = 0;
    solve();
    cout<<tans<<endl;
    return 0;
}

