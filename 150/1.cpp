#include <iostream>
using namespace std;

const int maxn = 1000;

int like[maxn][maxn];
int ori[maxn];

int main()
{
    int n, k;
    cin>>n>>k;

    for (int i = 1; i <= n*k; ++i)
    {
        ori[i] = 1;
    }

    for (int i = 1; i <= k; ++i)
    {
        cin>>like[i][1];
        ori[ like[i][1] ] = 0;

        like[i][0] = 2;
    }

    int index = 1;
    for (int i = 1; i <= n*k; ++i)
    {
        if (1 == ori[i])
        {
            if (like[index][0] <= n)
            {
                like[index][ like[index][0] ] = i;
                ++like[index][0];
            }
            else
            {
                ++index;
                like[index][ like[index][0] ] = i;
                ++like[index][0];
            }
        }
    }

    for (int i = 1; i <= k; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (j == 1)
            {
                cout<<like[i][j];
            }
            else
            {
                cout<<" "<<like[i][j];
            }
        }
        cout<<endl;
    }

    return 0;
}

