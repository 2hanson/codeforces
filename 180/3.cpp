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

int main()
{
    string a;
    string b;
    cin>>a>>b;
    int cnta = 0;
    int cntb = 0;
    for (int i = 0; i < a.length(); ++i)
    {
        if (a[i] == '1')
        {
            ++cnta;
        }
    }

    for (int i = 0; i < b.length(); ++i)
    {
        if (b[i] == '1')
        {
            ++cntb;
        }
    }

    if (cnta%2 != 0)
    {
        ++cnta;
    }
    if (cnta >= cntb)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }

    return 0;
}

