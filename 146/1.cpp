#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int al[28];

int main()
{
    string userName;
    for (int i = 0; i <= 26; ++i)
    {
        al[i] = 0;
    }
    cin>>userName;
 
    int num = 0;
    for (int i = 0; i < userName.size(); ++i)
    {
        int index = userName[i] - 'a';
        if ( al[index] == 0)
        {
            al[index] = 1;
            ++num;
        }
    }


    if (num % 2 != 0)
    {   
        cout<<"IGNORE HIM!"<<endl;
    }
    else
    {
        cout<<"CHAT WITH HER!"<<endl;
    }
    return 0;
}

