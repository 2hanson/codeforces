#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const string &http = "http";
const string &ftp = "ftp";
const string &ru = "ru";

int main()
{
    string str;
    cin>>str;

    int pos = 0;
    if ((pos = str.find(http, 0)) == 0)
    {
        cout<<"http://";
        //pos = 4;
        pos = str.find(ru, 5);
        
        cout<<str.substr(4, pos - 4)<<".ru";
        
        if (pos+1 < str.length()-1)
        {
            cout<<"/"<<str.substr(pos+2);
        }
        
        cout<<endl;
    }
    else if ((pos = str.find_first_of(ftp, 0)) == 0)
    {
        cout<<"ftp://";
        pos = 3;

        pos = str.find(ru, 4);
        cout<<str.substr(3, pos - 3)<<".ru";
        
        if (pos+1 < str.length()-1)
        {
            cout<<"/"<<str.substr(pos+2);
        }
        
        cout<<endl;
    }
}

