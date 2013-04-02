#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int x[3];
int y[3];
int a[3];
int b[3];
int c[3];

int ans;

void test()
{
    cout<<"fff"<<endl;
    for (int i = 0; i < 3; ++i)
    {
        cout<<x[i]<<" "<<y[i]<<endl;
    }
    cout<<"fff"<<endl;
}

bool init()
{
    ans = 0;
    bool flag = false;
    for (int i = 0; i < 3; ++i)
    {
        cin>>x[i]>>y[i];
        a[i] = b[i] = c[i] = 0;
        if (x[i]!=0 || y[i]!=0)
        {
            flag = true;
        }
    }

    return flag;
}

bool yucmp(int f, int s)
{
    if (x[f] < x[s])
    {
        return false;
    }
    else if (x[f] > x[s])
    {
        return true;
    }
    else
    {
        return y[f] > y[s];
    }
}

void bubblesort()
{
    for (int i = 0; i < 3; ++i)
    {
        int tmp = i;
        for (int j = i+1; j < 3; ++j)
        {
           if (yucmp(tmp, j) == true)
           {
                tmp = j;
           }
        }
        if (tmp != i)
        {
            swap(x[i], x[tmp]);
            swap(y[i], y[tmp]);
        }
    }
}

void calabc(int i1, int i2, int index)
{
    if (x[i1] == x[i2])
    {
        a[index] = 1;
        b[index] = 0;
        c[index] = x[i1];
    }
    else if (y[i1] == y[i2])
    {
        a[index] = 0;
        b[index] = 1;
        c[index] = y[i1];
    }
    else
    {
        a[index] = y[i2]-y[i1];
        b[index] = x[i1]-x[i2];
        c[index] = ( (y[i1]-y[i2])*x[i1] - (x[i1]-x[i2])*y[i1] );
    }
}

//ax+by+c = 0
void calequ()
{
    //line: (x0,y0), (x1, y1)
    calabc(0, 1, 0); 
    //line: (x0,y0), (x2, y2) 
    calabc(0, 2, 1); 
    //line: (x1,y1), (x2, y2) 
    calabc(1, 2, 2); 
}

int cp(int x1, int y1, int x2, int y2)
{
    return x1*y2-x2*y1;
}

void solve()
{
    int diff[2];
    int h, l;
    for (int index = x[0]+1; index < x[2]; ++index)
    {
        int can = 0;
        //line: (x0,y0), (x1, y1)
        if (index>x[0] && index < x[1])
        {
            diff[can] = -(a[0]*index + c[0])/b[0];
            if ((a[0]*index + c[0]) % b[0] == 0)
            {
                if (cp(x[1]-x[0], y[1]-y[0], x[2]-x[0], y[2]-y[0])  > 0)
                {
                    ++diff[can];
                    l = diff[can];
                }
                else
                {
                    --diff[can];
                    h = diff[can];
                }
            }
            ++can;
        }
        //line: (x0,y0), (x2, y2) 
        if (index>x[0] && index < x[2])
        {
            diff[can] = -(a[1]*index + c[1])/b[1];
            if ((a[1]*index + c[1]) % b[1] == 0)
            {
                if (cp(x[2]-x[0], y[2]-y[0], x[1]-x[0], y[1]-y[0])  > 0)
                {
                    ++diff[can];
                    l = diff[can];
                }
                else
                {
                    --diff[can];
                    h = diff[can];
                }
            }
            ++can;
        }
        //line: (x1,y1), (x2, y2) 
        if (index>x[1] && index < x[2])
        {
            diff[can] = -(a[2]*index + c[2])/b[2];
            if ((a[2]*index + c[2]) % b[2] == 0)
            {
                if (cp(x[2]-x[1], y[2]-y[1], x[0]-x[1], y[0]-y[1])  > 0)
                {
                    ++diff[can];
                    l = diff[can];
                }
                else
                {
                    --diff[can];
                    h = diff[can];
                }
            }
            ++can;
        }
        if (can == 2)
        {
            if (h < l)
            {
                continue;
            }
            ans += (1+h-l);
        }
    }
}

void output()
{
    cout<<ans<<endl;
}

int main()
{
    while (init() != false)
    {
        bubblesort(); 
        calequ();
        solve();
        output();
    }
    return 0;
}

