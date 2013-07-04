#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

#define LL long long
using namespace std;

const int maxn = 505;
int n, m;
char block[maxn][maxn];
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
bool isValid(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < m);
}

bool findCenter(int ct) {
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            int tmp = 0;
            for (int i = 0; i < 4; ++i) {
                int tr = r+dr[i];
                int tc = c+dc[i];
                if (!isValid(tr, tc) || block[tr][tc] != '.') {
                    continue;
                }
                ++tmp;
            }
            if (tmp == ct) {

                return true;
            }
        }
    }

    return false;
}

int main()
{
    cin>>n>>m;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            cin>>block[r][c];
        }
    }
    int center = 4;
    while (center>0) {
        if (findCenter( center )) {
            continue;
        }
        else {
            --center;
        }
    }
    return 0;
}

