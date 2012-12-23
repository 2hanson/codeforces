#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    bool flag = true;
    for (int i = 1; i <= 8 && flag == true; ++i)
    {
        cin>>str;
        for (int i = 1; i < str.length(); ++i)
        {
            if (str[i] == str[i-1])
            {
                flag = false;
                break;
            }
        }
    }

    if (flag == true)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}
