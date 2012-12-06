#include <iostream>
using namespace std;

int xNum[105];

int main()
{
    int n;
    cin>>n;

    int ans = -1;

    for (int index = 1; index <= n; ++index)
    {
        cin>>xNum[index];
        if (xNum[index] > ans)
        {
            ans = xNum[index];
        }

        for (int k = 1; k < index; ++k)
        {
            xNum[k] = xNum[k] ^ xNum[index];

            if (xNum[k] > ans)
            {
                ans = xNum[k];
            }
        }


    }

    cout<<ans<<endl;
    return 0;
}

