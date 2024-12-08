#include <bits/stdc++.h>
using namespace std;

class GraphColoring {
 public:
  bool isSafe(vector<vector<int>>& graph, int v, vector<int>& colors, int color) {
    for (int i = 0; i < graph.size(); i++) {
      if (graph[v][i] && colors[i] == color) {
        return false;
      }
    }
    return true;
  }

  bool graphColoringUtils(vector<vector<int>>& graph, int v, int m, vector<int>& colors) {
    if (v == graph.size()) {
      return true;
    }

    for (int c = 1; c <= m; c++) {
      if (isSafe(graph, v, colors, c)) {
        colors[v] = c;
        if (graphColoringUtils(graph, v + 1, m, colors)) {
          return true;
        } else {
          colors[v] = 0;
        }
      }
    }

    return false;
  }

  bool graphColor(vector<vector<int>>& graph, int m) {
    vector<int> colors(graph.size(), 0);
    return graphColoringUtils(graph, 0, m, colors);
  }
};

int main() {
  GraphColoring gc;

  // Example graph (adjacency matrix representation)
  vector<vector<int>> graph = {
      {0, 1, 1, 1},
      {1, 0, 1, 0},
      {1, 1, 0, 1},
      {1, 0, 0, 1},
      {1, 0, 1, 0}};

  // int m = 3;  // Maximum number of colors

  for (int m = 0; m < graph.size(); m++) {
    if (gc.graphColor(graph, m)) {
      cout << "Solution exists with " << m << " colors." << endl;
      return m;
    } else {
      cout << "Solution does not exist with " << m << " colors." << endl;
    }
  }

  // if (gc.graphColor(graph, m)) {
  //   cout << "Solution exists with " << m << " colors." << endl;
  // } else {
  //   cout << "Solution does not exist with " << m << " colors." << endl;
  // }

  return 0;
}
