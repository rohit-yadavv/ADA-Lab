#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, vector<int>& weight, vector<int>& profit, int idx, vector<vector<int>>& dp) {
  // Base Case: No items left or weight capacity is 0
  if (idx < 0 || W == 0) {
    return 0;
  }

  if (dp[idx][W] != -1) {
    return dp[idx][W];
  }

  if (weight[idx] > W) {
    return dp[idx][W] = knapSack(W, weight, profit, idx - 1, dp);
  }

  return dp[idx][W] = max(
             profit[idx] + knapSack(W - weight[idx], weight, profit, idx - 1, dp),  // Include the item
             knapSack(W, weight, profit, idx - 1, dp)                               // Exclude the item
         );
}

int main() {
  int W = 50;
  vector<int> profit = {60, 100, 120};
  vector<int> weight = {10, 20, 30};
  int n = profit.size();

  // Memoization table initialized to -1
  vector<vector<int>> dp(n, vector<int>(W + 1, -1));

  // Call the knapSack function
  cout << "Maximum profit: " << knapSack(W, weight, profit, n - 1, dp) << endl;

  return 0;
}
