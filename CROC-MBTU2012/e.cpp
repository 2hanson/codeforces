#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;

    cin>>str;

    int plus = 0;

    int cur = 0;
    int temp = 0;

    int stackindex = 0;

    for (int index = 0; index < str.length(); ++index)
    {
        if (str[index] == '+')
        {
            ++stackindex;
            ++temp;

            if (temp > cur)
            {
                cur = temp;
            }
        }
        else if (str[index] == '-')
        {
            --temp;
            if (temp <= 0)
                temp = 0;
            if (stackindex > 0)
            {
                --stackindex;
            }
            else
            {
                ++cur;
            }
           
            if (temp > cur)
            {
                cur = temp;
            }
        }
    }

    cout<<cur<<endl;

    return 0;
}
