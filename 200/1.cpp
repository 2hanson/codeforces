#include <iostream>
using namespace std;

int main()
{
    long n;
    cin>>n;
    int ans = 0;
    string str;
    char last = '2';
    while (n--) {
        cin>>str;
        if (last != str[0]) {
            ++ans;
        }
        last = str[0];
    }
    cout<<ans<<endl;
    return 0;
}
