#include <iostream>
using namespace std;

int main()
{
    int n, t;
    cin>>n>>t;
    string str[2];
    cin>>str[0];
    str[1][n] = '\0';
    int cur = 0;
    while (t--)
    {
        for (int i = 0; i < n;)
        {
            if (str[cur][i] == 'B' && i+1<n && str[cur][i+1] == 'G')
            {
                str[1-cur][i] = 'G';
                str[1-cur][i+1] = 'B';
                i = i + 2;
            }
            else
            {
                str[1-cur][i] = str[cur][i];
                ++i;
            }
        }
        cur = 1-cur;
    }

        for (int i= 0; i < n; ++i)
        {
            cout<<str[cur][i];
        }
    cout<<endl;
    return 0;
}

