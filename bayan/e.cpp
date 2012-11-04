#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

#define INF (1<<29)

int V,E;
int a[5010],b[5010];
bool graph[1010][1010];
bool s[1010],t[1010];
int x[1010];

bool func(void){
    int i,j;
    
    REP(i,V) x[i] = INF;
    x[0] = 0;
    REP(i,V+10) REP(j,E) if(s[a[j]] && t[b[j]]){
        x[b[j]] = min(x[b[j]], x[a[j]] + 2);
        x[a[j]] = min(x[a[j]], x[b[j]] - 1);
    }
    
    REP(j,E) if(s[a[j]] && t[b[j]]){
        int d = x[b[j]] - x[a[j]];
        if(d != 1 && d != 2) return false;
    }
    
    return true;
}

int main(void){
    int i,j;
    
    cin >> V >> E;
    REP(i,E){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    
    REP(i,E) graph[a[i]][b[i]] = true;
    s[0] = true;
    for(i=1;i<V;i++) REP(j,i) if(graph[j][i] && s[j]) s[i] = true;
    t[V-1] = true;
    for(i=V-2;i>=0;i--) for(j=i+1;j<V;j++) if(graph[i][j] && t[j]) t[i] = true;
    
    bool ans = func();
    if(!ans){
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        REP(i,E){
            if(!s[a[i]] || !t[b[i]]){
                cout << 1 << endl;
            } else {
                cout << x[b[i]] - x[a[i]] << endl;
            }
        }
    }
    
    return 0;
}
