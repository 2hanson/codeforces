#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

class P
{
    public:
    long x;
    long y;
};
long n;
double maxAngle = 0;
vector<P> mq;
void init()
{
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        P p;
        cin>>p.x>>p.y;
        mq.push_back(p);
    }
}

/*
 * 两个向量之间的旋转角
 * 首先明确几个数学概念：
 * 1. 极轴沿逆时针转动的方向是正方向
 * 2. 两个向量之间的夹角theta， 是指(A^B)/(|A|*|B|) = cos(theta)，0<=theta<=180 度， 而且没有方向之分
 * 3. 两个向量的旋转角，是指从向量p1开始，逆时针旋转，转到向量p2时，所转过的角度， 范围是 0 ~ 360度
 * 计算向量p1到p2的旋转角，算法如下：
 * 首先通过点乘和arccosine的得到两个向量之间的夹角
 * 然后判断通过差乘来判断两个向量之间的位置关系
 * 如果p2在p1的顺时针方向, 返回arccose的角度值, 范围0 ~ 180.0(根据右手定理,可以构成正的面积)
 * 否则返回 360.0 - arecose的值, 返回180到360(根据右手定理,面积为负)
 */ 
double getRotateAngle(double x1, double y1, double x2, double y2)
{
 const double epsilon = 1.0e-7;
 const double nyPI = acos(-1.0);
 double dist, dot, degree, angle;
 
 // normalize
 dist = sqrt( x1 * x1 + y1 * y1 );
 x1 /= dist;
 y1 /= dist;
 dist = sqrt( x2 * x2 + y2 * y2 );
 x2 /= dist;
 y2 /= dist;
 // dot product
 dot = x1 * x2 + y1 * y2;
 if ( fabs(dot-1.0) <= epsilon ) 
  angle = 0.0;
 else if ( fabs(dot+1.0) <= epsilon ) 
  angle = nyPI;
 else {
  double cross;
  
  angle = acos(dot);
  //cross product
  cross = x1 * y2 - x2 * y1;
  // vector p2 is clockwise from vector p1 
  // with respect to the origin (0.0)
  if (cross < 0 ) { 
   angle = 2 * nyPI - angle;
  }    
 }
 degree = angle *  180.0 / nyPI;
 return degree;
}

bool cmp(const P &p1, const P &p2)
{
    return getRotateAngle(1, 1, p1.x, p1.y) < getRotateAngle(1, 1, p2.x, p2.y);
}

void solve()
{
    sort(mq.begin(), mq.end(), cmp);

    int len = mq.size();
    maxAngle = 0;
    for (int i = 0; i < len; ++i)
    {
        double tempAngle = getRotateAngle(mq[i].x, mq[i].y, mq[(i+1) % len].x, mq[(i+1) % len].y);
        if (tempAngle > maxAngle)
        {
            maxAngle = tempAngle;
        }
    }
}

void output()
{
    if (maxAngle == 0.000000)
    {
        maxAngle = 360.0;
    }

    printf("%.10lf\n", 360.0 - maxAngle);
}

int main()
{
    init();
    solve();
    output();
    return 0;
}

