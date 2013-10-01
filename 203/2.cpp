#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> type(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        cin>>type[i];
    }
    vector<int> post(n+1, 0);
    vector<int> pre(n+1, 0);
    int r;
    for (int i = 1; i <= n; ++i) {
        cin>>r;
        if (r == 0) {
            continue;
        }
        if (post[r] == 0) {
            post[r] = i;
        }
        else {
            type[r] = -1;
        }
        pre[i] = r;
    }
    type[0] = -1;
    int id = -1, opt = -1, tmp = 0, k;
    for (int i = 1; i <= n; ++i) {
        if (type[i] == 1) {
            tmp = 1;
            k = i;
            while ( type[ pre[k] ] == 0 ) {
                k = pre[k];
                ++tmp;
            }
            if (tmp > opt) {
                opt = tmp;
                id = i;
            }
        }
    }
    cout<<opt<<endl;
    vector<int> ids;
    ids.push_back(id);
    while (type[ pre[id] ] == 0) {
        id = pre[id];
        ids.push_back(id);
    }
    cout<<ids[ids.size()-1];
    for (int i = ids.size()-2; i >= 0; --i) {
        cout<<" "<<ids[i];
    }
    cout<<endl;
    return 0;
}

