#include <algorithm>
#include <iostream>
using namespace std;

const long maxn = 100005;
long n, k;
long min_heap[maxn];

void update_heap(long top)
{
    long left = 2*top + 1;
    long right = 2*top + 2;
    
    if (left >= n)
        return;
    else if (right >= n)
    {
        if (min_heap[left] < min_heap[top])
        {
            swap(min_heap[left], min_heap[top]);
            update_heap(left);
        }
    }
    else
    {
        long min = left;
        if (min_heap[right] < min_heap[min])
        {
            min = right;
        }

        if (min_heap[min] >= min_heap[top])
        {
            return;
        }

        swap(min_heap[min], min_heap[top]);
        update_heap(min);
    }

    return;
}

int main()
{
    cin>>n>>k;
    for (long i = 0; i < n; ++i)
    {
        cin>>min_heap[i];
    }
    
    for (long i = 0; i < k; ++i)
    {
        min_heap[0] = -min_heap[0];
        update_heap(0);
    }

    long long ans = 0;
    for (long i = 0; i < n; ++i)
    {
        ans += min_heap[i];
    }
    cout<<ans<<endl;

    return 0;
}

