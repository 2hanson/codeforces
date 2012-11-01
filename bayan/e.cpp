#include <iostream>
using namespace std;

const int maxn = 5005;
int map[maxn][maxn];
int fA[1005];
int fB[1005];
int n, m;

void BFS()
{
   
}

int main()
{
    cin>>n>>m;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = i; j <= m; ++j)
        {
            map[i][j] = map[j][i] = -1;
        }
    }

    for (int index = 1; index <= n; ++index)
    {
        cin>>fA[index]>>fB[index];
        map[ fA[index] ][ fB[index] ] = 1;
    }

    
    BFS();

    return 0;
}
