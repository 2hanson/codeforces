#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int top;
    cin>>top;
    bool flag = false;
    while (n--)
    {
        int a, b;
        cin>>a>>b;
        if (top == a || top == b)
        {
            flag = true;
        }
        else if (top+a == 7 || top+b == 7)
        {
            flag = true;
        }
    }

    if (flag == true)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
    }

    return 0;
}
