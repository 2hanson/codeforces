#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int si = 1, fi = 0, limit = 3, curCnt = 1, preCnt = 0;
    for (fi = 1; fi < str.length(); ++fi) {
        if (str[fi] == str[fi-1]) {
            ++curCnt;
        }
        else {
            preCnt = curCnt;
            curCnt = 1;
        }
        //case 1
        if (preCnt < 2) {
            if (curCnt < 3) {
                str[si++] = str[fi];
            }
            else {
                --curCnt;
            }
        }
        //case 2
        else {
            if (curCnt < 2) {
                str[si++] = str[fi];
            }
            else {
                --curCnt;
            }
        }
    }
    str = str.substr(0, si);
    cout<<str<<endl;
    return 0;
}
