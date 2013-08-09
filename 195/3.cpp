#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> bitRec[35];
    int n, index, num, tmp = 1;
    cin>>n;
    for (int i = 1; i <= 30; ++i) {
        tmp |= (int)(1<<(i-1)); 
        bitRec[i].push_back(tmp);
    }
    for (int i = 0; i < n; ++i) {
        cin>>num;
        tmp = num, index = 0;
        while (tmp) {
            if (tmp & 1) {
                bitRec[index+1][0] &= num, bitRec[index+1].push_back(num);
            }
            ++index, tmp>>=1;
        }
    }
    for (int i = 30; i >= 1; --i) {
        if ( !(bitRec[i][0] & (bitRec[i][0]-1)) && bitRec[i].size()>1) {
            cout<<bitRec[i].size()-1<<endl;
            for (int k = 1; k < bitRec[i].size(); ++k) {
                if (k > 1) { cout<<" "; }
                cout<<bitRec[i][k];
            }
            cout<<endl;
            return 0;
        }
    }
    cout<<n<<endl;
    bool first = true;
    for (int i = 1; i <= 30; ++i) {
        for (int k = 1; k < bitRec[i].size(); ++k) {
            if (!first) { cout<<" "; }
            cout<<bitRec[i][k];
            first = false;
        }
    }
    cout<<endl;
    return 0;
}
