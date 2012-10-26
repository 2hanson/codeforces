#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 2505;

int table[maxn][maxn];
int col[maxn];

int oprR[maxn];
int oprC[maxn];
int oriR[maxn];
int oriC[maxn];
int ansR[maxn];
int ansC[maxn];

int main()
{
    int n;
    cin>>n;
    for (int index = 1; index <= n; ++index)
    {
        cin>>col[index];
    }

    for (int r = 1; r <= n; ++r)
    {
        for (int c = 1; c <= col[r]; ++c)
        {
            cin>>table[r][c];
        }
    }

    int ans = 0;

    for (int r = n; r >= 1; --r)
    {
        for (int c = col[r]; c >= 1; --c)
        {
            oprR[r] = r;
            oprC[c] = c;
            for (int tr = r; tr >= 1; --tr)
            {
                for (int tc = c; tc >= 1; --tc)
                {
                    if (table[tr][tc] > table[ oprR[r] ][ oprC[c] ])
                    {
                        oprR[r] = tr;
                        oprC[c] = tc;
                    }
                }
            }

            if (oprR[r] != r || oprC[c] != c)
            {
                ++ans;
                //cout<<"test: "<<r<<" "<<c<<endl;
                ansR[ans] = oprR[r];
                ansC[ans] = oprC[c];
                oriR[ans] = r;
                oriC[ans] = c;
                //cout<<oprR[r]<<" "<<oprC[c]<<" "<<r<<" "<<c<<endl;
                int temp = table[r][c];
                table[r][c] = table[ oprR[r] ][ oprC[c] ];
                table[ oprR[r] ][ oprC[c] ] = temp;
                //++ans;
            }
            
        }
    }

    cout<<ans<<endl;
    for (int index = 1; index <= ans; ++index)
    {
        cout<<ansR[index]<<" "<<ansC[index]<<" "<<oriR[index]<<" "<<oriC[index]<<endl;
    }
    /*
    for (int r = n; r >= 1; --r)
    {
        for (int c = col[r]; c >= 1; --c)
        {
            if (oprR[r] != r || oprC[c] != c)
            {
                cout<<oprR[r]<<" "<<oprC[c]<<" "<<r<<" "<<c<<endl;
            }
        }
    }*/
    return 0;
}
