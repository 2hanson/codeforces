#include <algorithm>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int x = 0;
    int n;
    cin>>n;
    while (n--)
    {
        string state;
        cin>>state;
        if (state[1] == '+')
        {
            ++x;
        }
        else if (state[1] == '-')
        {
            --x;
        }
    }

    cout<<x<<endl;

    return 0;
}

