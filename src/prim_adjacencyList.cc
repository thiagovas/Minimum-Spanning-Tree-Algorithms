#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MAX 1000000
#define INF 0x3f3f3f3f
typedef long long int ll;

bool connected[MAX];

int main()
{
  ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  int n, m, u, v, w, edgeCount=0;
  vector<vector<pair<int, int> > > graph;
  
  cin >> n >> m;
  graph.resize(n);
  while(m--)
  {
    cin >> u >> v >> w;
    u--;  v--;
    graph[u].push_back(make_pair(w, v));
    graph[v].push_back(make_pair(w, u));
  }
  

  memset(connected, false, sizeof(connected));
  for(int i = 0; i < n; i++)
  {
    if(connected[i]) continue;
    connected[i]=true;
    

    set<pair<pair<int, int>, int> > tempEdges;
    for(unsigned j = 0; j < graph[i].size(); j++) tempEdges.insert(make_pair(graph[i][j], i));
    
    while(not tempEdges.empty() && edgeCount+1 < n)
    {
      pair<pair<int, int>, int> edge = *tempEdges.begin();
      tempEdges.erase(tempEdges.begin());
      if(not connected[edge.first.second])
      {
        connected[edge.first.second]=true;
        edgeCount++;
        for(unsigned j = 0; j < graph[edge.first.second].size(); j++)
          if(not connected[graph[edge.first.second][j].second])
            tempEdges.insert(make_pair(graph[edge.first.second][j], edge.first.second));
        cout << edge.second+1 << " " << edge.first.second+1 << endl;
      }
    }
  }
  
  return 0;
}
