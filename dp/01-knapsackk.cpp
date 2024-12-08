#include <bits/stdc++.h>
using namespace std;

class Item {
 public:
  int profit;
  int weight;

  Item(int profit, int weight) {
    this->profit = profit;
    this->weight = weight;
  }
};

class Knapsack {
 public:
  int W;
  Knapsack(int W) {
    this->W = W;
  }

  int find(vector<Item>& arr, int idx, vector<vector<int>> memo, int W) {
    if (idx < 0) {
      return 0;
    }
    if (memo[idx][W] != -1) {
      return memo[idx][W];
    }

    if (arr[idx].weight <= W) {
      memo[idx][W] = max(arr[idx].profit + find(arr, idx - 1, memo, W - arr[idx].weight),
                         find(arr, idx - 1, memo, W));
    } else {
      memo[idx][W] = find(arr, idx - 1, memo, W);
    }
    return memo[idx][W];
  }

  int findMaxProfit(vector<Item>& arr) {
    vector<vector<int>> memo(arr.size() + 1, vector<int>(W + 1, -1));
    return find(arr, arr.size() - 1, memo, W);
  }
};

int main() {
  vector<Item> items = {
      Item(60, 10),
      Item(100, 20),
      Item(120, 30),
  };

  int W = 50;
  Knapsack knapsack(W);

  cout << "Maximum Profit: " << knapsack.findMaxProfit(items) << endl;

  return 0;
}
