#include <bits/stdc++.h>
using namespace std;

class Graph {
 public:
  int V;
  vector<vector<pair<int, int>>> adj;  // Adjacency list: {node, weight}

  Graph(int V) {
    this->V = V;
    adj.resize(V);
  }

  void addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  vector<int> dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INT_MAX);

    dist[src] = 0;
    pq.push({0, src});  // {distance, node}

    while (!pq.empty()) {
      int d = pq.top().first;
      int node = pq.top().second;
      pq.pop();

      if (d < dist[node]) continue;

      for (auto edge : adj[node]) {
        int adjNode = edge.first;
        int weight = edge.second;

        if (dist[node] + weight < dist[adjNode]) {
          dist[adjNode] = dist[node] + weight;
          pq.push({dist[adjNode], adjNode});
        }
      }
    }
    return dist;
  }
};

int main() {
  int V = 6;
  Graph g(V);

  g.addEdge(0, 1, 4);
  g.addEdge(0, 2, 4);
  g.addEdge(1, 2, 2);
  g.addEdge(1, 3, 5);
  g.addEdge(2, 3, 8);
  g.addEdge(3, 4, 6);
  g.addEdge(4, 5, 9);

  int src = 0;  // Source node
  vector<int> distances = g.dijkstra(src);

  cout << "Shortest distances from node " << src << ":\n";
  for (int i = 0; i < V; ++i) {
    cout << "Node " << i << " : " << distances[i] << "\n";
  }

  return 0;
}
