#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define LL long long
using namespace std;
const long maxn = 100000;

struct line
{
    long left,right;//左端点、右端点
    LL n;//记录这条线段出现了多少次，默认为0
};
struct line a[maxn];
LL sum;
//建立
void build(long s,long t,long n)
{
    long mid=(s+t)/2;
    a[n].left=s;
    a[n].right=t;
    if (s==t) return;
    a[n].left=s;
    a[n].right=t; 
    build(s,mid,2*n);
    build(mid+1,t,2*n+1);
} 
//插入

void insert(long s,long t,long step)//要插入的线段的左端点和右端点、以及当前线段树中的某条线段
{     if (s==a[step].left && t==a[step].right)
    {
        a[step].n++;//插入的线段匹配则此条线段的记录+1
        return;//插入结束返回
    }
    if (a[step].left==a[step].right)   return;//当前线段树的线段没有儿子，插入结束返回
    long mid=(a[step].left+a[step].right)/2;
    if (mid>=t)    insert(s,t,step*2);//如果中点在t的右边，则应该插入到左儿子
    else if (mid<s)    insert(s,t,step*2+1);//如果中点在s的左边，则应该插入到右儿子
    else//否则，中点一定在s和t之间，把待插线段分成两半分别插到左右儿子里面
    {
        insert(s,mid,step*2);
        insert(mid+1,t,step*2+1);
    }
}
//访问

void yucount(long s,long t,long step)
{   
    if (a[step].n!=0)
        sum=sum+a[step].n*(t-s+1);
    if (a[step].left==a[step].right)
        return;
    long mid=(a[step].left+a[step].right)/2;
    if (mid>=t)
        yucount(s,t,step*2);
    else
        if (mid<s)
            yucount(s,t,step*2+1);
        else
        {
            yucount(s,mid,step*2);
            yucount(mid+1,t,step*2+1);
        }
}

long n, m, k;

int main()
{
    long t;
    cin>>n>>m>>k;
    build(0, n-1, 0);
    for (int i = 0; i < n; ++i)
    {
        cin>>t;
        while (t--)
        {
            cout<<t<<endl;
            insert(i, i, 0);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        sum = 0;
        yucount(i,i,0);
        cout<<sum<<endl;
    }
    return 0;
}

