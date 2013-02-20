#include <algorithm>    
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int grid[3][3];
int dr[5] = {0, 0,0,1,-1};
int dc[5] = {0, 1,-1,0,0};

bool validr(int tr)
{
    if (tr < 0)
        return false;

    if (tr>=3)
        return false;

    return true;
}

bool validc(int tc)
{
    if (tc < 0)
        return false;

    if (tc >= 3)
    {
        return false;
    }

    return true;
}

void toggle(int tr, int tc)
{
    for (int i = 0; i < 5; ++i)
    {
        if (validr(tr+dr[i]) && validc(tc+dc[i]))
        {
            grid[tr+dr[i]][tc+dc[i]] = 1 - grid[tr+dr[i]][tc+dc[i]];
        }
    }
}

void output()
{
    for (int r = 0; r < 3; ++r)
    {
        for (int c = 0; c < 3; ++c)
        {
            cout<<grid[r][c];
        }
        cout<<endl;
    }
}

int main()
{
    for (int r = 0; r < 3; ++r)
    {
        for (int c = 0; c < 3; ++c)
        {
            grid[r][c] = 1;
        }
    }
    int p;
    for (int r = 0; r < 3; ++r)
    {
        for (int c = 0; c < 3; ++c)
        {
            cin>>p;
            if (p%2 != 0)
            {
                toggle(r, c);     
            }
        }
    }
    
    output();

    return 0;
}

