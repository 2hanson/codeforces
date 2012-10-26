#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if (n%2 != 0)
    {
        cout<<-1<<endl;
    } 
    else
    {
        bool first = true;
        while (n--)
        {
            if (!first)
            {
                cout<<" ";
            }
            cout<<(n+1);
            first = false;
        }
        cout<<endl;
    }

    return 0;
}
