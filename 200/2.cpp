#include <iostream>
using namespace std;

int main()
{
    long a, b, c;
    cin>>a>>b>>c;
    if ((a+b-c)%2==0 && (a+b-c)>=0 && (a+c-b)%2==0 && (a+c-b)>=0 && (b+c-a)%2==0 && (b+c-a)>=0) {
        cout<<(a+b-c)/2<<" "<<(b+c-a)/2<<" "<<(c+a-b)/2<<endl;
    }
    else {
        cout<<"Impossible"<<endl;
    }
    return 0;
}
