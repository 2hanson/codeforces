#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

int hashMap[4003];
map<int,int> hMap;
int hashCnt;

int mymap[4003][4003];
int array[4003];

int hash(int n){
    for(map<int,int>::const_iterator iter=hMap.begin();iter!=hMap.end();++iter)
        if(iter->first==n)
            return iter->second;
    hMap[n]=hashCnt;
    return hashCnt++;
}
int main(){
    hashCnt=0;
    int mx=0;
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>array[i];
        array[i]=hash(array[i]);
    }
    memset(mymap,0,sizeof(mymap));
    for(int i=0;i<n;++i){
        for(int j=0;j<hashCnt;++j){
            mx=max(mx,mymap[j][array[i]]=mymap[array[i]][j]+1);
        }
    }
    cout<<mx<<endl;
    return 0;
}
