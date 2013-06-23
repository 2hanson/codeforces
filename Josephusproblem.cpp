#include <iostream>
#include <queue>
using namespace std;

class Solution
{
    private:
        int n, m;
        queue<int> q;
    public:
        Solution(int tn, int tm)
        {
            n = tn;
            m = tm;
            while (q.empty() == false)
            {
                q.pop();
            }
        }

        void init()
        {
            for (int i = 0; i < n; ++i)
            {
                q.push(i);
            }
        }

        void solve()
        {
            while (q.empty() == false)
            {
                for (int i = 0; i < m-1; ++i)
                {
                    q.push( q.front() );
                    q.pop();
                }

                cout<<q.front()<<endl;
                q.pop();
            }
        }
};

int main()
{
    return 0;
}

