#include <iostream>
#include <cmath>
using namespace std;

const int maxn = 105;
int dp[maxn][maxn] = {0};
int pre[maxn][maxn][2];

bool isB(int x, int y, int px, int py)
{
    double dis = sqrt((x-px)*(x-px) + (y-py)*(y-py));
    int idis = (int)dis;
    return (dis == double(idis));
}

int main()
{
    int n, m;
    cin>>n>>m;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            dp[i][j] = 1;
            pre[i][j][0] = -1;
            pre[i][j][1] = -1;
        }
    }

    //exclude (0, 0)
    dp[0][0] = -1000;
    //遍历节点
    for (int x = 0; x <= n; ++x)
    {
        for (int y = 0; y <= m; ++y)
        {

            //
            for (int px = 0; px < x; ++px)
            {
                for (int py = 0; py <= m; ++py)
                {
                    if (py == y)
                    {
                        continue;
                    }

                    if (!isB(x, y, px, py))
                    {
                        if (dp[x][y] < (dp[px][py] + 1))
                        {
                            dp[x][y] = (dp[px][py] + 1);
                            pre[x][y][0] = px;
                            pre[x][y][1] = py;
                        }
                    }
                }
            }
        }
    }

    for (int x = 0; x <= n; ++x)
    {
        for (int y = 0; y <= m; ++y)
        {
            cout<<" "<<dp[x][y];
        }
        cout<<endl;
    }

    return 0;
}

