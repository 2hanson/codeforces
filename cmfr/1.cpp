#include <iostream>
using namespace std;

int b[105];

int main()
{
    int n;
    cin>>n;
    
    int a;
    int ans = 0;
    int countNeg = 0;
    for (int index = 0; index < n; ++index)
    {
        cin>>a;
        if (a < 0)
        {
            ++countNeg;
        }

        if (countNeg == 3)
        {
            ++ans;
            countNeg = 1;
        }

        b[ans]++;
    }

    cout<<ans+1<<endl;
    for (int i = 0; i <= ans; ++i)
    {
        if (i > 0)
            cout<<" ";
        cout<<b[i];
    }
    cout<<endl;

    return 0;
}

