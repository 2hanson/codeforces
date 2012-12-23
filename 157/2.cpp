#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin>>str;
    bool flag = true;
    for (int i = 0; i < str.length(); ++i)
    {
        if (flag == true && str[i] == '0')
        {
            flag = false;
            continue;
        }
        else if (flag == false)
        {
            cout<<str[i];
        }
        else if (i < str.length() - 1)
        {
            cout<<str[i];
        }
        else if (i == str.length() -1)
        {
            break;
        }
    }

    cout<<endl;
    return 0;
}

