#include <iostream>
using namespace std;

const long maxn = 100006;

long genre[maxn]; 
long days[maxn];

int main()
{
    long n, k;
    long temp;
    long num = 1;

    cin>>n>>k;

    long ans;
    for ( int i = 1; i <= k; ++i )
    {
        genre[i] = 0;
    }
    cin>>days[1];
    ans = 1;
    for (int index = 2; index <= n; ++index)
    {
        cin>>temp;
        
        if (temp != days[ num ])
        {
            days[++num] = temp;
        }
/*
        genre[temp]++;
        if (genre[temp] > genre[ans])
        {
            ans = temp;
        }
        else if (genre[temp] == genre[ans] && temp < ans)
        {
            ans = temp;
        }*/
    }


    for (int i = 1; i <= num; ++i)
    {
        temp = days[i];
        genre[temp]++;

        if (genre[temp] > genre[ans])
        {
            ans = temp;
        }
        else if (genre[temp] == genre[ans] && temp < ans)
        {
            ans = temp;
        }


        if (i != 1 && i != num && days[i-1] == days[i+1])
        {
            genre[ temp ]++;

            if (genre[temp] > genre[ans])
            {
                ans = temp;
            }
            else if (genre[temp] == genre[ans] && temp < ans)
            {
                ans = temp;
            }
        }
        //cout<<days[i]<<" ";
    }

    cout<<ans<<endl;
    return 0;
}

