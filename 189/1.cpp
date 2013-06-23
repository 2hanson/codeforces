#include <iostream>
using namespace std;

void getdigit(long &tmp, long &n)
{
    tmp = n % 10;
    n = n / 10;
}

int main()
{
    long n;
    cin>>n;
    bool isok = true;
    long tmp;

    if (n == 0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    while (n)
    {
        getdigit(tmp, n);
        if (tmp == 1)
        {
            continue;
        }
        else if (tmp == 4)
        {
            getdigit(tmp, n);
            if (tmp == 1)
            {
                continue;
            }
            else if (tmp == 4)
            {
                getdigit(tmp, n);
                if (tmp == 1)
                {
                    continue;
                }
                else
                {
                    isok = false;
                    continue;
                }
            }
            else
            {
                isok = false;
                break;
            }
        }
        else
        {
            isok = false;
            break;
        }
    }

    cout<<(isok ? "YES" : "NO" )<<endl;
    return 0;
}

