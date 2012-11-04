#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long ans[15];

void reset()
{
    for (int i = 0; i < 10; ++i)
    {
        ans[i] = 0;
    }
}

void outPut()
{
    cout<<ans[0];
    for (int i = 1; i < 10; ++i)
    {
        cout<<" "<<ans[i];
    }
    cout<<endl;
}
 
int main()
{
    
    int n, q;
    cin>>n>>q;
    string str;
    cin>>str;
    int l, r;
    while (q--)
    {
        reset();

        cin>>l>>r;

        --l;
        --r;

        int len = (r - l + 1);

        string sub = str.substr(l, len);

        int dir = 1;//1 right, -1 left
        int cur = 0;


        while (cur>=0 && cur<len)
        {
            //digit
            if (sub[cur] == '*')
            {
                cur += dir;
                if (cur<0 || cur>=len)
                {
                    break;
                }
            }
            else if (sub[cur]>='0' && sub[cur]<='9')
            {
                if (sub[cur]-'0' > 0)
                {
                    ++ans[ sub[cur]-'0' ];
                    sub[cur] -= 1;
                    cur += dir;
                }
                else
                {
                    ++ans[0];
                    sub[cur] = '*';
                    cur += dir;
                }

                if (cur<0 || cur>=len)
                {
                    break;
                }
            }
            else if (sub[cur] == '>')
            {
                dir = 1;
                int pre = cur;
                cur += dir;
                while (sub[cur]=='*')
                {
                    cur+=dir;
                }
                if (cur<0 || cur>=len)
                {
                    break;
                }

                if (sub[cur] == '>' || sub[cur] == '<')
                {
                    sub[pre] = '*';
                }
            }
            else if (sub[cur] == '<')
            {
                
                int pre = cur;
                dir = -1;
                cur += dir;
            
                while (sub[cur]=='*')
                {
                    cur+=dir;
                }
                if (cur<0 || cur>=len)
                {
                    break;
                }
                if (sub[cur] == '>' || sub[cur] == '<')
                {
                    sub[pre] = '*';
                }
            }
            else 
                break;
        }
        //cout<<sub<<endl;
        outPut();
    }

    return 0;
}
