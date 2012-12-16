#include <iostream>
#include <string>
using namespace std;

    
long m[3] = {0};
string e[3] = {"chest","biceps", "back"};
int main()
{   
    int n;
    cin>>n;
    int temp;
    for (int i = 0; i < n; ++i)
    {
        cin>>temp;
        m[i%3] += temp;
    }

    int ans = 0;
    if (m[1] > m[ans])
    {
        ans = 1;
    }
    if (m[2] > m[ans])
    {
        ans = 2;
    }

    cout<<e[ans]<<endl;

    return 0;
}

