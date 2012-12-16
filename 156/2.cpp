#include <iostream>
#include <string>
using namespace std;

string str;

int main()
{
    cin>>str;
    bool flag = true;
    long i;

    while (flag)
    {
        flag = false;
        for (i = 0; i < str.size()-1 && flag == false; ++i)
        {
           if (str[i] == 'y' && str[i+1]=='x')
           {
                str[i] = 'x';
                str[i+1] = 'y';
                flag = true;
                break;
           }
        }

        string::iterator it;
        for (it = str.begin(); it != str.end() && flag == false; ++it)
        {
            if ((it+1) == str.end())
            {
                break;
            }

           if ( *it == 'x' && *(it+1)=='y')
           {
            
               str.erase(it+1);
               str.erase(it);
               flag = true;
               break;
           }
        }
    }

    cout<<str<<endl;
    return 0;
}
