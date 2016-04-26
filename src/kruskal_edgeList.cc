#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 0x3f3f3f3f
#define MAX 1000000
typedef long long int ll;

typedef struct sEdge{
  sEdge(){}
  sEdge(int _u, int _v, int _w)
  {
    u = _u;
    v = _v;
    w = _w;
  }
  int u, v, w;
} edge;

int muf[MAX];

void InitUnionFind(int n)
{ for(int i = 0; i <= n; i++) muf[i]=i; }

int Find(int a)
{ return muf[a]==a ? a : (muf[a]=Find(muf[a])); }

void Union(int a, int b)
{
  muf[Find(a)] = Find(b);
}


bool comp(edge a, edge b)
{
  return a.w < b.w;
}

int main()
{
  ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  
  int n, m, u, v, w;
  vector<edge> ve;
  
  cin >> n >> m;
  InitUnionFind(n);
  while(m--)
  {
    cin >> u >> v >> w;
    ve.push_back(sEdge(u, v, w));
  }
  sort(ve.begin(), ve.end(), comp);
  
  ll finalWeight=0;
  for(unsigned i = 0; i < ve.size(); i++)
  {
    if(Find(ve[i].v) != Find(ve[i].u))
    {
      Union(ve[i].u, ve[i].v);
      finalWeight += ve[i].w;
      cout << ve[i].u << " " << ve[i].v << endl;
    }
  }
  
  return 0;
}
