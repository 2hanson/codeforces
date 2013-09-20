#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> nums;
    int tmp;
    for (int i = 0; i < n; ++i) {
        cin>>tmp;
        nums.push_back(tmp);
    }
    sort(nums.begin(), nums.end());
    swap(nums[0], nums[n-1]);
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            cout<<nums[i];
        }
        else {
            cout<<" "<<nums[i];
        }
    }
    cout<<endl;
}
