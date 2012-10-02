#include <iostream>
#include <cmath>

using namespace std;

int n;
long long t;

bool isP(long long x)
{

    for(long long i = 2; i <= (long long)sqrt(x); i++)
    
    {
    
        if((x % i) == 0)
        
            return false;
            
    }

    
    return true;
}

int main()
{
    cin>>n;

    while (n--)
    {
        cin>>t;

        if (t == 1)
        {
            cout<<"NO"<<endl;
        }

        else
        {
            long long sq = sqrt(t);
        
            if (isP(sq) && sq*sq == t)
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}
