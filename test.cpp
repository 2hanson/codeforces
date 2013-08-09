#include <iostream>
using namespace std;

int main()
{
    int a, b;
    int tmp;
    long long t2;
    while (cin>>a>>b ) {
    tmp = a + b;
    t2 += (long long)(a + b);
    cout<<tmp<<endl<<t2<<endl;
    }
    return 0;
}
