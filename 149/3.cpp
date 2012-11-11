#include <iostream>
using namespace std;

const long maxn = 100005;

long x0, y0, x1, y1;

long ans;
long validField[maxn][3];
long n;
long length;

void insertSort(long r, long a, long b, long len)
{
    long index;
    for (index = len - 1; index >= 0; --index)
    {
        if (validField[index][0] == r)
        {
            if (a > validField[index][1])
            {
                break;
            }
            if (b < validField[index][2])
            {
                break;
            }
            if (a < validField[index][1])
            {
                validField[index][1] = a;
            }
            if (b > validField[index][2])
            {
                validField[index][2] = b;
            }
            
            return;
        }
        else if (validField[index][0] < r)
        {
            break;
        }
    }

    long temp = index+1; 
    for (index = len; index > temp; --index)
    {
        validField[index][0] = validField[index-1][0];
        validField[index][1] = validField[index-1][1];
        validField[index][2] = validField[index-1][2];
    }

    ++length;

    validField[temp][0] = r;
    validField[temp][1] = a;
    validField[temp][2] = b;
}

void Out()
{
    for (int index = 0; index < length; ++index)
    {
        cout<<validField[index][0];
        cout<<validField[index][1];
        cout<<validField[index][2];
        cout<<endl;
    }
}

bool BFS()
{
    
}

int main()
{
    cin>>x0>>y0>>x1>>y1;
    
    cin>>n;
    length = 0;
    long r, a, b;
    for (long i = 1; i <= n; ++i)
    {
        cin>>r>>a>>b;
        
        insertSort(r, a, b, length);
    }

    ans = 0;
    if (BFS()) {
    //Out();
        cout<<ans<<endl;
    }
    else
    {
        cout<<"-1"<<endl;
    }
    return 0;
}

