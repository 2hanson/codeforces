#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    long n;
    scanf("%ld", &n);
    long k, cnt[8];
    for (int i = 0; i < 8; ++i) {
        cnt[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%ld", &k);
        ++cnt[k];
    }
    if (cnt[0] || cnt[5] || cnt[7]) {
        printf("-1\n");
        return 0;
    }
    int a1 = cnt[1], a2 = cnt[2], a3 = cnt[3], a4 = cnt[4], a6 = cnt[6];
    while (a4 > 0) {
        --a1, --a2, --a4;
    }
    while (a2 > 0) {
        --a1, --a2, --a6;
    }
    while (a3 > 0) {
        --a1, --a3, --a6;
    }
    if (a1 || a2 || a3 || a4 || a6) {
        printf("-1\n");
        return 0;
    }
    while (cnt[4] > 0) {
        printf("1 2 4\n");
        --cnt[1], --cnt[2], --cnt[4];
    }
    while (cnt[2] > 0) {
        printf("1 2 6\n");
        --cnt[1], --cnt[2], --cnt[6];
    }
    while (cnt[3] > 0) {
        printf("1 3 6\n");
        --cnt[1], --cnt[3], --cnt[6];
    }
    return 0;
}
