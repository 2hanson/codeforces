#include<iostream>
using namespace std;
const int MAXV = 10000001; //素数表范围
bool flag[MAXV+1]; //标志一个数是否为素数
int prime[MAXV+1]; //素数表,下标从0开始
int size; //素数个数
void genPrime(int max)
{
    for (int i = 0; i <= max; ++i) {
        flag[i] = true;
    }
    for(int i = 2; i <= max/2; i++) {
        if(flag[i]){
            for(int j = i << 1 ; j <= max; j += i) {
                flag[j] = false;
            }
        }
    }
    size = 0;
    for(int i = 2 ; i <= max; i++) {
        if(flag[i]) {
            prime[size++] = i;
        }
    }
}
int main()
{
    genPrime(MAXV);
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            cout<<" ";
        }
        cout<<prime[i];
    }
    cout<<endl;
    return 0;
}
