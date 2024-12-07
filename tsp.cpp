#include <climits>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class TravelingSalesmanProblem {
 private:
  int numCities;                 // Number of cities
  vector<vector<int>> distance;  // Distance matrix

 public:
  TravelingSalesmanProblem(int cities, vector<vector<int>> distMatrix)
      : numCities(cities), distance(distMatrix) {}

  // Function to solve the TSP problem and return the minimum cost
  int solve() {
    set<int> remainingCities;
    for (int i = 1; i < numCities; i++) {
      remainingCities.insert(i);
    }

    vector<int> path;
    path.push_back(0);
    return tspUtil(0, remainingCities, 0);
  }

  // Recursive utility function to calculate TSP and return minimum cost
  int tspUtil(int currentCity, set<int>& remainingCities, int currentCost) {
    if (remainingCities.empty()) {
      return currentCost + distance[currentCity][0];
    }

    int minCost = INT_MAX;  // Initialize min cost for this recursion level

    // Try visiting all remaining cities
    for (int nextCity : remainingCities) {
      set<int> newRemainingCities = remainingCities;  // Copy the current set
      newRemainingCities.erase(nextCity);             // Remove the next city from remaining

      // Recursive call to visit the next city
      int totalCost = tspUtil(nextCity, newRemainingCities, currentCost + distance[currentCity][nextCity]);
      minCost = min(minCost, totalCost);
    }

    return minCost;
  }
};

int main() {
  int numCities = 4;
  vector<vector<int>> distanceMatrix = {
      {0, 10, 15, 20},
      {10, 0, 35, 25},
      {15, 35, 0, 30},
      {20, 25, 30, 0}};

  TravelingSalesmanProblem tsp(numCities, distanceMatrix);
  int minCost = tsp.solve();
  cout << "Minimum cost: " << minCost << endl;

  return 0;
}