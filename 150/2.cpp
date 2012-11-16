#include <iostream>
using namespace std;

int isUnlucky(long long num)
{
    int count = -1;
    int arr[5];
    bool flag;
    arr[0] = arr[1] = arr[2] = -1;

    while (num > 0)
    {
        if (count >= 2)
        {
            return 0;
        }
        
        int temp = num % 10;
        flag = false;
        for (int i = 0; i <= count && flag == false; ++i)
        {
            if (arr[i] == temp)
            {
                flag = true;
            }
        }

        if (flag == false)
        {
            ++count;
            arr[count] = temp;
        }
        if (count >= 2)
        {
            return 0;
        }
        num /= 10;
    }

    return 1;
}

int main()
{
    long long n;
    cin>>n;
    if (n <= 100)
    {
        cout<<n<<endl;
    }
    else 
    {
        long long un = 0;
        for (long long index = 101; index <= n; ++index)
        {
            if (0 == isUnlucky(index))
            {
                ++un;
            }
        }

        cout<<(n - un)<<endl;
    }
    return 0;
}
