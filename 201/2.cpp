#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr;
    int tmp, n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>tmp;
        arr.push_back(tmp);
    }
    int ans = 0, diff = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == i) {
            ++ans;
            continue;
        }
        if (diff != 2) {
            diff = 1;
        }
        if ( arr[ arr[i] ] == i ) {
            diff = 2;
        }
    }
    cout<<ans+diff<<endl;
}
