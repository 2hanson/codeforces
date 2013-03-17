#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define LL long long
using namespace std;

int main()
{
    long n;
    cin>>n;
    string str;
    cin>>str;
    long an = 0;
    long in = 0;
    long fn = 0;
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == 'A')
        {
            ++an;
        }
        else if (str[i] == 'I')
        {
            ++in;
        }
        else if (str[i] == 'F')
        {
            ++fn;
        }
    }

    if (in == 0)
    {
        cout<<an<<endl;
    }
    else if (in == 1)
    {
        cout<<1<<endl;
    }
    else
    {
        cout<<"0"<<endl;
    }

    return 0;
}

