#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
    
long m, q, tq, n;
vector<long> vec;

int main()
{
    q = 100006;
    cin>>m;
    while(m--)
    {
        cin>>tq;
        if (tq < q)
        {
            q = tq;
        }
    }

    vec.clear();
    cin>>n;
    for (long i = 0; i < n; ++i)
    {
        cin>>tq;
        vec.push_back(tq);
    }
    sort(vec.begin(), vec.end());
    
    long long ans = 0;
   
    long index = vec.size() -1;
    while (index >= 0)
    {
        for (int i = 0; i < q; ++i)
        {
            ans += vec[index];
            --index;
            if (index < 0)
            {
                break;
            }
        }
        
        index -= 2;
    }
    
    cout<<ans<<endl;
    return 0;
}

