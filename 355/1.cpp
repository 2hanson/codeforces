#include <iostream>
using namespace std;

int main()
{
    int k, d;
    cin>>k>>d;
    if (d == 0) {
        if (k == 1) {
            cout<<0<<endl;
        }
        else {
            cout<<"No solution"<<endl;
        }
    }
    else {
        cout<<d;
        --k;
        while (k > 0) {
            cout<<0;
            --k;
        }
        cout<<endl;
    }
    return 0;
}
