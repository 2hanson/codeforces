#include <iostream>
#include <string>
using namespace std;

void out(int digit) {
    if (digit < 5) {
        cout<<"O-|";
    }
    else {
        digit -= 5;
        cout<<"-O|";
    }
    for (int i = 0; i < digit; ++i) {
        cout<<"O";
    }
    cout<<"-";
    for (int i = 0; i < 4-digit; ++i) {
        cout<<"O";
    }
    cout<<endl;
}

int main()
{
    long n;
    cin>>n;
    if (n == 0) {
        out(0);
        return 0;
    }
    while (n) {
        out(n % 10);
        n /= 10;
    }
    return 0;
}
