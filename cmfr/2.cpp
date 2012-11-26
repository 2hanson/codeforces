#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string st;
    int n;
    cin>>n;
    vector<string> vstr;

    while (n--)
    {
        cin>>st;
        
        string temp;

        temp.clear();

        for (int index = 0; index < st.size() - 1; ++index)
        {
           if (st[ index ] == ':')
           {
               if (temp.size() > 0)
               {
                    vstr.push_back(temp);
                    temp.clear();
               }
           
               if (st[index+1] == ':')
               {     
                    temp += "::";
                    vstr.push_back(temp);
                    temp.clear();
                }
           }
           else
           {
                temp += st[ index ];
           }
        }

        if (st[ st.size()-1 ] != ':')
        {
            temp += st[st.size() - 1];
            vstr.push_back( temp );

            temp.clear();
        }

        for (int i = 0; i < vstr.size(); ++i)
        {
            if (i > 0)
            {
                cout<<":";
            }
            if (vstr[i].compare("::") == 0)
            {
               for (int k = 0; k <= 8 - vstr.size(); ++k)
               {
                
                    if (k > 0)
                    {
                        cout<<":";
                    }

                    for (int j = 0; j < 4; ++j)
                    {
                        cout<<"0";
                    }
               }
            }
            //cout<<vstr[i]<<endl;
            else
            {
                for (int j = 0; j < 4-vstr[i].size(); ++j)
                {
                    cout<<"0";
                }
                cout<<vstr[i];
            }
            
        }
       
        cout<<endl;
        vstr.clear();
    }
    return 0;
}

