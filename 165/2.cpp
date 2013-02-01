#include <iostream>
#include <stdio.h>
using namespace std;

const long maxn = 100005;

long th[maxn];

int main()
{
    long n;
    scanf("%ld", &n);
    long ans = 0;
    long rec = -1;

    for (int i = 0; i < n; ++i)
    {
        scanf("%ld", &th[i]);
        for (int k = i-1; k >= i-1; --k)
        {
            if (k < rec)
            {
                break;
            }

            if (th[k] > th[i])
            {
                if (k > rec)
                {
                    rec = k;
                }
                th[k] = -1;
            }
        }
    }

    for (int k = n-1; k >= 0; --k)
    {
        if (th[k] == -1)
        {
            ans = k+1;
            break;
        }
    }

    printf("%ld\n", ans);
    return 0;
}

