#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int count = 0;
    while (n--)
    {
        int i, j, k;
        cin>>i>>j>>k;
        int sol = i + j + k;
        if (sol >= 2)
        {
            count++;
        }
    }
    cout<<count<<endl;

    return 0;

}
