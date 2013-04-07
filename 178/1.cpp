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

int main()
{
   int n;
   cin>>n;
   int b[105];
   for (int i = 1; i <= n; ++i)
   {
    cin>>b[i];
   }
   int m;
   cin>>m;
   while (m--)
   {
    int x, y;
    cin>>x>>y;
    b[x-1] += (y-1);
    //b[x] = 0;
    b[x+1] += (b[x] - y);
    b[x] = 0;
   }
   for (int i = 1; i <= n; ++i)
   {
    cout<<b[i]<<endl;
   }
   return 0;
}

