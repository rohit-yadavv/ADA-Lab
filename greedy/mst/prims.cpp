#include <bits/stdc++.h>
using namespace std;

class MinSpanningTree {
 public:
  int SumOfWeightsOfMinimumSpanningTree(int V, vector<vector<pair<int, int>>>& adj) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // Min-heap (priority queue) to get the edge with the minimum weight

    vector<int> visited(V, 0);
    pq.push({0, 0});  // {weight, vertex}

    int sum = 0;

    while (!pq.empty()) {
      auto it = pq.top();
      pq.pop();
      int node = it.second;
      int wt = it.first;

      if (!visited[node]) {
        visited[node] = 1;
        sum += wt;

        // Traverse all adjacent nodes
        for (auto neighbor : adj[node]) {
          if (!visited[neighbor.first]) {
            pq.push({neighbor.second, neighbor.first});
          }
        }
      }
    }
    return sum;
  }
};

int main() {
  int V = 5;
  vector<vector<pair<int, int>>> adj(V);

  adj[0].push_back({1, 2});
  adj[0].push_back({2, 1});
  adj[1].push_back({0, 2});
  adj[1].push_back({2, 1});
  adj[2].push_back({0, 1});
  adj[2].push_back({1, 1});
  adj[2].push_back({3, 2});
  adj[2].push_back({4, 2});
  adj[3].push_back({2, 2});
  adj[3].push_back({4, 1});
  adj[4].push_back({2, 2});
  adj[4].push_back({3, 1});

  MinSpanningTree mst;
  int sum = mst.SumOfWeightsOfMinimumSpanningTree(V, adj);
  cout << "The sum of all the edge weights in the MST: " << sum << endl;

  return 0;
}
