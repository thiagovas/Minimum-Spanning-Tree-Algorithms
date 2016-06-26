#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 0x3f3f3f3f
#define MAX 10000000
typedef long long int ll;
typedef long double ld;

int muf[MAX];

void InitUnionFind(int n)
{ for(int i = 0; i <= n; i++) muf[i]=i; }

int Find(int a)
{ return muf[a]==a ? a : (muf[a]=Find(muf[a])); }

void Union(int a, int b)
{ muf[Find(a)] = Find(b); }

bool comp(const pair<int, double> &a, const pair<int, double> &b)
{ return a.second < b.second; }


int main()
{
  ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  int n, m, u, v;
  double w;
  vector<vector<pair<int, double> > > graph;
  vector<int> relativePosition;
  
  cin >> n >> m;
  graph.resize(n);
  InitUnionFind(n);
  while(m--)
  {
    cin >> u >> v >> w;
    
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
  }
  for(unsigned i = 0; i < graph.size(); i++)
    sort(graph[i].begin(), graph[i].end(), comp);
  relativePosition.assign(n, 0);
  
  int edges=0;
  ld finalWeight = 0;
  while(edges < n-1)
  {
    // Index and value of the next possible edge to be added to the mst.
    int edgeIndex=-1;
    double edgeValue=INF;
    for(unsigned i = 0; i < relativePosition.size(); i++)
    {
      int index=relativePosition[i];
      if(index < (int)graph[i].size())
      {
        if(graph[i][index].second < edgeValue)
        {
          edgeValue = graph[i][index].second;
          edgeIndex = i;
        }
      }
    }
    
    // This condition is only true in cases where the graph is not connected.
    if(edgeIndex==-1) break;
    
    u = edgeIndex;
    v = graph[edgeIndex][relativePosition[edgeIndex]].first;
    if(Find(u) != Find(v))
    {
      Union(u, v);
      edges++;
      finalWeight += graph[edgeIndex][relativePosition[edgeIndex]].second;
      cout << u << " " << v << endl;
    }
    
    relativePosition[edgeIndex]++;
  }
  cout << "Weight: " << std::fixed << std::setprecision(8) << finalWeight << endl;
  
  return 0;
}
