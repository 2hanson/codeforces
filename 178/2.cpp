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

int n;
int ans;
int dp[300];
int used[300];
int tolT;
int tolW;

class Book
{
    public:
        int t;
        int w;
        Book(int tt, int tw)
        {
            t = tt;
            w = tw;
        }
};

vector<Book*> books;

int main()
{
    cin>>n;
    books.clear();
    Book *tmp;
    int tt, tw;
    tolT = 0;
    tolW = 0;
    for (int i = 0; i < n; ++i)
    {
        used[i] = 0;
        cin>>tt>>tw;
        tolW += tw;
        tolT += tt;
        tmp = new Book(tt, tw);
        books.push_back(tmp);
    }

    //dp[t] = max(dp[t], dp[t-1]+w, dp[t-2]+w);
    dp[0] = 0;
    int tmpT;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i)
    {
        for (tmpT = tolT; tmpT >= 1; --tmpT)
        {
            if (tmpT - books[i]->t < 0)
            {
                continue;
            }

            if (dp[tmpT] < (dp[tmpT-books[i]->t] + books[i]->w))
            {
                if (tmpT-books[i]->t>0 && dp[tmpT-books[i]->t]==0)
                {
                    continue;
                }

                dp[tmpT] = (dp[tmpT-books[i]->t] + books[i]->w);
            }
        }
    }

    for (tmpT = 1; tmpT < tolT; ++tmpT)
    {
        if (tmpT >= (tolW-dp[tmpT]))
        {
            break;
        }
    }

    cout<<tmpT<<endl;
    return 0;
}

