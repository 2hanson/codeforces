#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

const double epsilon = 1.0e-9;
const double nyPI = acos(-1.0);
long n;
double maxAngle = 0;
vector<double> aq;
void init()
{
    double x, y;
    cin>>n;
    aq.clear();
    for (int i = 0; i < n; ++i)
    {
        scanf("%lf %lf", &x, &y);
        aq.push_back( atan2(y, x) );
    }
}

void solve()
{
    sort(aq.begin(), aq.end());

    int len = aq.size();
    maxAngle = 0;
    for (int i = 0; i < len; ++i)
    {
        double tempAngle = aq[(i+1)%len] - aq[i];

        if (tempAngle <= -epsilon)
        {
            tempAngle += 2*nyPI;
        }
        
        if (tempAngle > maxAngle)
        {
            maxAngle = tempAngle;
        }
    }
}

void output()
{
    if (maxAngle <= epsilon)
    {
        printf("%.10lf\n", 0.0);
        return;
    }

    printf("%.10lf\n", 360.0 - maxAngle*180/nyPI);
}

int main()
{
    init();
    solve();
    output();
    return 0;
}

