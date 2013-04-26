#include <iostream>

#define LL long long
using namespace std;

const int maxn = 305;
LL ans;
int w, h;
LL board[maxn][maxn];

void floodfill()
{

}

int main()
{    
    scanf("%d %d", &w, &h);
    for (int r = 0; r < h; ++r)
    {
        for (int c = 0; c < w; ++c)
        {
            cin>>board[r][c];
        }
    }

    ans = 0;
    floodfill();
    cout<<ans<<endl;

    return 0;
}
