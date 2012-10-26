#include <iostream>
using namespace std;

const int maxn = 105;

long com[maxn];
long record[maxn];
int num = 0;
long ans;

void countC(int k)
{

    if (k == 0)
        return;

    for (int index = 3; index <= 100; ++index)
    {
        long tk = (index*(index-1)*(index+1))/6;
        if (tk > k)
        {
            countC(k - tk*(index-2)/(index+1));
            
            //cout<<"index = "<<index<<" tk = "<<tk*(index-2)/(index+1)<<endl;
            com[num++] = index;
            ans += index;
            break;
        }
    }
}

bool isInSameSet(int first, int second)
{
    int fIndex = -1;
    int sIndex = -1;
    for (int i = 1; i <= num; ++i)
    {
        if (first > record[i-1] && first <= record[i])
        {
            fIndex = i;
        }
        if (second > record[i-1] && second <= record[i])
        {
            sIndex = i;
        }

        if (fIndex != -1 && sIndex != -1)
        {
            break;
        }
    }

    return (fIndex == sIndex);
}

void printCOM()
{
    cout<<ans<<endl;
    
    record[0] = 0;

    for (int index = 0; index < num; ++index)
    {
        record[index + 1] = record[index] + com[index];

        //cout<<"index = "<<com[index]<<" tk = "<<com[index]*(com[index]-1)*(com[index]-2)/6<<endl;
    }

    for (int low = 1; low <= ans; ++low)
    {
        for (int col = 1; col <= ans; ++col)
        {
            if (low == col)
            {
                cout<<0;
            }
            else if (isInSameSet(low, col)){
                cout<<1;
            }
            else
            {
                cout<<0;
            }
        }
        cout<<endl;
    }
}

int main()
{
    long low = 3;
    long high = 100;

    long k;
    cin>>k;
    
    num = 0;
    ans = 0;

    countC(k);

    printCOM();
    /*long mid;

    while (low <= high)
    {
        
        mid = (low+high)/2;

        long tk = (mid*(mid-1)*(mid-2))/6;

        if (tk == k)
        {
            break;
        }
        else if (tk > k)
        {
            high = mid - 1;
        }
        else
        {
            low = mid+1;
        }
    }

    cout<<mid<<endl;
    for (int i = 0; i < mid; ++i)
    {
        for (int k = 0; k < mid; ++k)
        {
            if (i == k)
            {
                cout<<0;
            }
            else
            {
                cout<<1;
            }
        }
        cout<<endl;
    }*/
    return 0;
}
