#include <iostream>
using namespace std;

int col[100];

int main()
{
    int n;
    cin>>n;
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin>>col[i];
        sum += col[i];
    }

    for(int r = 1; r <= n; ++r)
    {
        for (int c = 1; c <= col[r]; ++c)
        {
            if (c != 1)
                cout<<" ";
            cout<<sum;
            --sum;
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
