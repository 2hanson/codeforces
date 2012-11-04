#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <ctime> 

using namespace std;

vector<int> a1[2000];
vector<int> a2[2000];
int d[2000];
int ans[6000];
int used1[2000];
int used2[2000];
int used[2000];

int main()
{
  int i,j,b1,n,m,x,y;
  vector<pair<int,int> > b;
  vector<int> q;
  scanf("%d%d",&n,&m);
  b.clear();
  for (i=0;i<n;i++)
  {
    a1[i].clear();
    a2[i].clear();
  }
  for (i=0;i<m;i++)
  {
    scanf("%d%d",&x,&y);
    x--;y--;
    b.push_back(make_pair(x,y));
    a1[x].push_back(y);
    a2[y].push_back(x);
  }
  memset(used1,0,sizeof(used1));
  q.clear();
  q.push_back(0);
  used1[0]=1;
  for (i=0;i<q.size();i++)
    for (j=0;j<a1[q[i]].size();j++)
      if (used1[a1[q[i]][j]]==0)
      {
        used1[a1[q[i]][j]]=1;
        q.push_back(a1[q[i]][j]);
      }
  memset(used2,0,sizeof(used2));
  q.clear();
  q.push_back(n-1);
  used2[n-1]=1;
  for (i=0;i<q.size();i++)
    for (j=0;j<a2[q[i]].size();j++)
      if (used2[a2[q[i]][j]]==0)
      {
        used2[a2[q[i]][j]]=1;
        q.push_back(a2[q[i]][j]);
      }
  memset(used,0,sizeof(used));
  for (i=0;i<n;i++)
    if ((used1[i]==1)&&(used2[i]==1))
      used[i]=1;
  
  
  
  
  for (i=0;i<n;i++)
    d[i]=-2000000000;
  d[0]=0;
  for (i=0;i<6000;i++)
    for (j=0;j<m;j++)
    {
      if ((used[b[j].first]==0)||(used[b[j].second]==0)) continue;
      if ((d[b[j].first]!=-2000000000)&&(d[b[j].first]+1>d[b[j].second]))
        d[b[j].second]=d[b[j].first]+1;
      if ((d[b[j].second]!=-2000000000)&&(d[b[j].second]-2>d[b[j].first]))
        d[b[j].first]=d[b[j].second]-2;
    }
  b1=1;
  for (j=0;j<m;j++)
  {
    if ((used[b[j].first]==0)||(used[b[j].second]==0)) continue;
    if ((d[b[j].first]!=-2000000000)&&(d[b[j].first]+1>d[b[j].second]))
    {
      d[b[j].second]=d[b[j].first]+1;
      b1=0;
    }
    if ((d[b[j].second]!=-2000000000)&&(d[b[j].second]-2>d[b[j].first]))
    {
      d[b[j].first]=d[b[j].second]-2;
      b1=0;
    }
  }
  if (b1==0) printf("No\n");
  else
  {
    printf("Yes\n");
    for (i=0;i<m;i++)
      if (d[b[i].first]+1==d[b[i].second]) printf("1\n");
      else printf("2\n");
  }
}
