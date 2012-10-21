#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long pFactor(long long input)
{
    long long ret = 1;
    long long pred = -1;
    long long num = 1;
    for (long long d = 2; d <= input; ++d)
    {
        if (input % d == 0)
        {
            if (pred == d)
            {
                ++num;
            }
            else
            {
                if (pred != -1)
                    ret = ret * (num+1);

                num = 1;
            }
              //cout<<" "<<d;
            input /= d;
            if (input == 1)
            {

                ret = ret * (num+1);
                break;
            }

            pred = d;

            --d;
        }
    }

    return ret % 1073741824;
}

int main()
{
    int a, b, c;
    cin>>a>>b>>c;

    long long sum = 0;

    for (int indexa = 1; indexa <= a; ++indexa)
    {
        for (int indexb = 1; indexb <= b; ++indexb)
        {
            for (int indexc = 1; indexc <= c; ++indexc)
            {
                sum += pFactor(indexa * indexb * indexc);
                sum = sum % 1073741824;
            }
        }
    }

    cout<<sum<<endl;

    return 0;
}

