#include <iostream>
using namespace std;

int main()
{
    int n, t, fiveCnt = 0, oneCnt = 0;
    cin>>n;
    while (n--) {
        cin>>t;
        if (t == 0) {
            ++oneCnt;
        }
        else {
            ++fiveCnt;
        }
    }
    fiveCnt /= 9;
    if (oneCnt==0) {
        cout<<"-1"<<endl;
    }
    else if (fiveCnt == 0) {
        cout<<"0"<<endl;
    }
    else {
        //cout<<five;
        while (fiveCnt > 0) {
            --fiveCnt;
            cout<<"555555555";
        }
        while (oneCnt > 0) {
            --oneCnt;
            cout<<"0";
        }
        cout<<endl;
    }
    return 0;
}

