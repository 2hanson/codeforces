#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

#define LL long long
using namespace std;

int main()
{
    long n, k;
    cin>>n>>k;
    if (n < k)
    {
        cout<<-1<<endl;
    }
    else
    {
        if (k == 1)
        {
            if (n == 1)
            {
                cout<<'a'<<endl;
            }
            else
            {
                cout<<-1<<endl;
            }
        }
        else
        {
            for (int i = 0; i < n-(k-2); ++i)
            {
                if (i % 2 == 0)
                {
                    cout<<'a';
                }
                else
                {
                    cout<<'b';
                }
            }
            int t = 2;
            for (int i = n-(k-2);i < n; ++i)
            {
                char ch = 'a' + t;
                cout<<ch;
                ++t;
            }
            cout<<endl;
        }
    }

    return 0;
}

