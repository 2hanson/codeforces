#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <ctime>
#include <list>
#include <iomanip>

using namespace std;
#define LL long long
#define DEBUG(x) cout<< #x << ":" << x <<endl
#define PII pair<int, int>
#define MP make_pair
//~x + 1, 负数补码
#define lowbit(x) (x&(-x))
#define INF (1<<30)
/*
 * int cmp(const Cs *a, const Cs *b)
 * {
 *      return a->v < b->v;
 * }
 *
 *sort(vec.begin(), vec.end(), cmp);
 * */

int main()
{
    int n;
    cin>>n;
    int t;
    vector<int> arr;
    for (int i = 0; i < n; ++i)
    {
        cin>>t;
        arr.push_back(t);
    }

    sort(arr.begin(), arr.end());
    
    vector<int> s1;
    vector<int> s2;
    vector<int> s3;
    s1.clear();
    s2.clear();
    s3.clear();
    if (arr[arr.size()-1] == 0)
    {
        s2.push_back(arr[0]); 
        s2.push_back(arr[1]);
        s1.push_back(arr[2]);
        for (int i = 3; i < arr.size(); ++i)
        {
                
            s3.push_back(arr[i]);
        }
    }
    else
    {
        s1.push_back(arr[0]);
        s2.push_back(arr[arr.size()-1]);
        for (int i = 1; i < arr.size()-1; ++i)
        {
                
            s3.push_back(arr[i]);
        }
    }

    cout<<s1.size();
    for (int i = 0; i < s1.size(); ++i)
    {
        cout<<" "<<s1[i];
    }
    cout<<endl;
    cout<<s2.size();
    for (int i = 0; i < s2.size(); ++i)
    {
        cout<<" "<<s2[i];
    }
    cout<<endl;

    cout<<s3.size();
    for (int i = 0; i < s3.size(); ++i)
    {
        cout<<" "<<s3[i];
    }
    cout<<endl;
    return 0;
}

