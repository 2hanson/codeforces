#include <iostream>
#include <string>
using namespace std;

long long ans;
long n, m;

char map[105][10005];

bool checkFloor(long floor)
{
    for (int i = 1; i <= m; ++i)
    {
        if (map[floor][i] != '#' && map[floor+1][i] == '.')
            return true;
    }
    return false;
}

//0 is right, 1 is left
bool startD(long floor, long cell, long dir, int isNewF)
{
    //cout<<floor<<" "<<cell<<endl;

    if (floor == n)
    {
        return true;
    }

    if (isNewF == 1 && checkFloor(floor) == false)
    {
        return false;
    }
    
    if (map[floor+1][cell] == '.')
    {
        ++ans;

        return startD(floor+1, cell, dir, 1);
    }
    else if (dir == 0)
    {
        if (cell == m)
        {
            ++ans;

            return startD(floor, cell, 1 - dir, 0);
        }
        else if (map[floor][cell+1] == '+')
        {
            ++ans;
            map[floor][cell+1] = '.';
            return startD(floor, cell, 1 - dir, 0);
        }
        else if(map[floor][cell+1] == '#')
        {
            ++ans;
            return startD(floor, cell, 1 - dir, 0);
        }
        else if(map[floor][cell+1] == '.')
        {
            ++ans;
            return startD(floor, cell+1, dir, 0);
        }
    }
    else if (dir == 1)
    {
        if (cell == 1)
        {
            ++ans;

            return startD(floor, cell, 1 - dir, 0);
        }
        else if (map[floor][cell-1] == '+')
        {
            ++ans;
            map[floor][cell-1] = '.';
            return startD(floor, cell, 1 - dir, 0);
        }
        else if(map[floor][cell-1] == '#')
        {
            ++ans;
            return startD(floor, cell, 1 - dir, 0);
        }
        else if(map[floor][cell-1] == '.')
        {
            ++ans;
            return startD(floor, cell-1, dir, 0);
        }
    }
}

int main()
{
    cin>>n>>m;
    
    for (int r = 1; r <= n; ++r)
    {
        for (int c = 1; c <= m; ++c)
        {
            cin>>map[r][c];
        }
    }

    /*
    for (int r = 1; r <= n; ++r)
    {
        for (int c = 1; c <= m; ++c)
        {
            cout<<map[r][c];
        }
        cout<<endl;
    }
    */
    ans = 0;
    //0 is right, 1 is left
    if (startD(1, 1, 0, 1) == true)
    {
        cout<<ans<<endl;
    }
    else
    {
        cout<<"Never"<<endl;
    }
    return 0;
}

