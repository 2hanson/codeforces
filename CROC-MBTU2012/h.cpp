#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define N 5005
using namespace std;

int n, m, x, y, t;
int r[N][N];
char p[N][N], s[N];

int main()
{
    scanf("%s", s);
    n = strlen(s);
    
    FOR(i,0,n){
        x = y = i;
        p[x][y] = 1;
        while (x && s[x-1] == s[y+1]) x--, y++, p[x][y] = 1;
        x = i + 1, y = i;
        while (x && s[x-1] == s[y+1]) x--, y++, p[x][y] = 1;
    }
                    
    FOD(i,n,0){
        t = 0;
        FOR(j,i,n){
            t += p[i][j];
            r[i][j] = r[i+1][j] + t;
        }
    }
    
    scanf("%d", &m);
    while (m--){
        scanf("%d%d", &x, &y), x--, y--;
        printf("%d\n", r[x][y]);
    }
    return 0;
}

