#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Edge {
 public:
  int u, v, weight;

  Edge(int u, int v, int weight) {
    this->u = u;
    this->v = v;
    this->weight = weight;
  }
};

class DisjointSet {
 public:
  vector<int> parent, rank;

  DisjointSet(int n) {
    parent.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  // Find the representative of a set (with path compression)
  int find(int node) {
    if (parent[node] != node) {
      parent[node] = find(parent[node]);
    }
    return parent[node];
  }

  // Union of two sets (by rank)
  void unite(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);

    if (rootU != rootV) {
      if (rank[rootU] > rank[rootV]) {
        parent[rootV] = rootU;
      } else if (rank[rootU] < rank[rootV]) {
        parent[rootU] = rootV;
      } else {
        parent[rootV] = rootU;
        rank[rootU]++;
      }
    }
  }
};

bool compareEdge(const Edge& a, const Edge& b) {
  return a.weight < b.weight;
}

vector<Edge> kruskalMST(int n, vector<Edge>& edges) {
  sort(edges.begin(), edges.end(), compareEdge);

  DisjointSet ds(n);
  vector<Edge> mst;
  // int minCost=0;

  for (const Edge& edge : edges) {
    int node1 = edge.u;
    int node2 = edge.v;

    // Check if the current edge forms a cycle
    if (ds.find(node1) != ds.find(node2)) {
      mst.push_back(edge);
      // minCost += edge.weight
      ds.unite(node1, node2);
    }
  }

  return mst;
}

int main() {
  // Number of vertices and edges
  int n = 4;  // 4 vertices
  vector<Edge> edges = {
      Edge(0, 1, 10),
      Edge(0, 2, 6),
      Edge(0, 3, 5),
      Edge(1, 3, 15),
      Edge(2, 3, 4)};

  vector<Edge> mst = kruskalMST(n, edges);

  cout << "Edges in the Minimum Spanning Tree:" << endl;
  for (const Edge& edge : mst) {
    cout << edge.u << " - " << edge.v << " : " << edge.weight << endl;
  }

  return 0;
}
