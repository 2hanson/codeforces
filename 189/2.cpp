#include <iostream>
#include <queue>
using namespace std;

const int maxn = 105;
int path[maxn][maxn];
int rx[maxn];
int ry[maxn];
int rc;
queue<int> bque;
bool mark[maxn];

void repath(int tx, int ty)
{
    for (int i = 1; i < rc; ++i)
    {
        if ((rx[i]<tx && tx<ry[i]) || (rx[i]<ty && ty<ry[i]))
        {
            path[ rc ][ i ] = 1;
        }
        if ((tx<rx[i] && rx[i]<ty) || (tx<ry[i] && ry[i]<ty))
        {
            path[ i ][ rc ] = 1;
        }
    }
}

void bfs(int s, int d)
{
    while (bque.empty() == false)
    {
        bque.pop();
    }   
    for (int i = 1; i <= rc; ++i)
    {
        mark[i] = 0;
    }
    bque.push(s);
    while (bque.empty() == false)
    {
        int cur = bque.front();
        bque.pop();
        if (cur != s)
            path[s][cur] = 1;
        if (cur == d)
        {
            return;
        }
        mark[cur] = 1;
        for (int i = 0; i <= rc; ++i)
        {
            if (mark[i] == 1)
                continue;
            if (path[cur][i] == 1)
            {
                bque.push(i); 
            }
        }
    }
}

int main()
{
    for (int i = 1; i < maxn; ++i)
    {
        for (int j = 1; j < maxn; ++j)
        {
            path[i][j] = 0;
        }
    }
    rc = 0;
    int n;
    int opt, x, y; 
    cin>>n;
    while (n--)
    {
        cin>>opt>>x>>y;
        if (opt == 1)
        {
           ++rc;
           rx[ rc ] = x;
           ry[ rc ] = y;
           repath(x, y);
        }
        else
        {
            if (path[x][y] == 1)
            {
                cout<<"YES"<<endl;
                continue;
            }

            bfs(x, y);

            if (path[x][y] == 1)
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
    }

    return 0;
}
