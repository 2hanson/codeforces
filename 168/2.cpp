#include <algorithm>    
#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int maxn = 55;
int grid[maxn][maxn];
int n, m;
int rec;
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

void test()
{
    for (int r = 0; r < n; ++r)
    {
        for (int c = 0; c < m; ++c)
        {
            cout<<grid[r][c]<<" ";
        }
        cout<<endl;
    }
}

bool validr(int tr)
{
    if (tr < 0)
        return false;

    if (tr>=n)
        return false;

    return true;
}

bool validc(int tc)
{
    if (tc < 0)
        return false;

    if (tc >= m)
    {
        return false;
    }

    return true;
}

void dfs(int tr, int tc)
{
    for (int i = 0; i < 4; ++i)
    {
        if (validr(tr+dr[i]) && validc(tc+dc[i]) && grid[tr+dr[i]][tc+dc[i]]==-1)
        {
            grid[tr+dr[i]][tc+dc[i]] = rec;
            dfs(tr+dr[i], tc+dc[i]);
        }
    }
}

bool yucheck(int r, int c)
{
    int res = 0;
    int tr, tc;
    //left
    tc = c-1;
    while (tc >= 0)
    {
        if (grid[r][tc] > 0)
        {
            ++res;
            break;
        }
        --tc;
    }
    //right
    tc = c + 1;
    while (tc < m)
    {
        if (grid[r][tc] > 0)
        {
            ++res;
            break;
        }
        ++tc;
    }
    //up
    tr = r-1;
    while (tr >= 0)
    {
        if (grid[tr][c] > 0)
        {
            ++res;
            break;
        }
        --tr;
    }
    //down
    tr = r+1;
    while (tr < n)
    {
        if (grid[tr][c] > 0)
        {
            ++res;
            break;
        }
        ++tr;
    }

    if (res >= 3)
        return true;

    return false;
}

int main()
{
    cin>>n>>m;
    char ch;
    rec = 0;
    for (int r = 0; r < n; ++r)
    {
        for (int c = 0; c < m; ++c)
        {
            cin>>ch;
            if (ch == 'W')
            {
                grid[r][c] = 0;
            }
            else
            {
                grid[r][c] = -1;
            }
        }
    }

    rec = 1;
    for (int r = 0; r < n; ++r)
    {
        for (int c = 0; c < m; ++c)
        {
            if (grid[r][c] == -1)
            {
                grid[r][c] = rec;
                dfs(r, c);
                ++rec;
            }
        }
    }


    if (rec > 2)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        bool flag = true;
        for (int r = 0; r < n && flag; ++r)
        {
            for (int c = 0; c < m && flag; ++c)
            {
                if (grid[r][c] == 0)
                {
                    if (yucheck(r, c) == true)
                    {
                        flag = false;
                        cout<<"NO"<<endl;
                    }
                }
            }
        }

        if (flag == true)
        {
            cout<<"YES"<<endl;
        }
    }
    return 0;
}

