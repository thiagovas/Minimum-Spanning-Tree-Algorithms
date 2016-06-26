#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <set>

#include <boost/heap/fibonacci_heap.hpp>


#define MAX 10000000
#define INF 0x3f3f3f3f
typedef long long int ll;

bool connected[MAX];

struct compare_edge {
  bool operator()(const std::pair<std::pair<int, int>, int> &a, const std::pair<std::pair<int, int>, int> &b) const
  {
    return a.first.first > b.first.first;
  }
};

int main()
{
  std::ios::sync_with_stdio(false);  std::cin.tie(0);  std::cout.tie(0);
  int n, m, u, v, w, edgeCount=0;
  std::vector<std::vector<std::pair<int, int> > > graph;
  
  std::cin >> n >> m;
  graph.resize(n);
  while(m--)
  {
    std::cin >> u >> v >> w;
    u--;  v--;
    graph[u].push_back(std::make_pair(w, v));
    graph[v].push_back(std::make_pair(w, u));
  }
  
  ll finalWeight = 0;
  memset(connected, false, sizeof(connected));
  for(int i = 0; i < n; i++)
  {
    if(connected[i]) continue;
    connected[i]=true;
    
    boost::heap::fibonacci_heap<std::pair<std::pair<int, int>, int>, boost::heap::compare<compare_edge> > tempEdges;
    for(unsigned j = 0; j < graph[i].size(); j++) tempEdges.push(std::make_pair(graph[i][j], i));
    
    while(not tempEdges.empty() && edgeCount+1 < n)
    {
      std::pair<std::pair<int, int>, int> edge = tempEdges.top();
      tempEdges.pop();
      if(not connected[edge.first.second])
      {
        connected[edge.first.second]=true;
        edgeCount++;
        for(unsigned j = 0; j < graph[edge.first.second].size(); j++)
          if(not connected[graph[edge.first.second][j].second])
            tempEdges.push(std::make_pair(graph[edge.first.second][j], edge.first.second));
        std::cout << edge.second+1 << " " << edge.first.second+1 << std::endl;
        finalWeight += edge.first.first;
      }
    }
  }
  std::cout << "Weight: " << finalWeight << std::endl;
  
  return 0;
}
