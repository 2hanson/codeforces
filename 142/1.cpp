#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1005;

typedef struct
{
    int x;
    int y;
}Dragon;

int cmp( const Dragon &a, const Dragon &b )
{
    if( a.x < b.x )
        return 1;
    else
        if( a.x == b.x ){
            if( a.y < b.y )
                return 1;
            else
                return 0;
        }
        else
            return 0;
}

int main()
{
    Dragon *dragons = new Dragon[maxn];
    int s, n;
    cin>>s>>n;

    for (int i = 0; i < n; ++i)
    {
        cin>>dragons[i].x>>dragons[i].y;
    }

    sort(dragons, dragons+n, cmp);

    int i;
    for ( i = 0; i < n; ++i)
    {
        if (dragons[i].x < s)
        {
            s += dragons[i].y;
        }
        else
        {
            break;
        }
            //cout<<dragons[i].x<<dragons[i].y;
    }

    if (i == n)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }

    return 0;
}
