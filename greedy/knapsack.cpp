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
 private:
  vector<Item> items;
  int W;
  int n;

 public:
  Knapsack(vector<Item> items, int W) {
    this->items = items;
    this->n = items.size();
    this->W = W;
  }

  static bool cmp(Item a, Item b) {
    return (double)a.profit / a.weight > (double)b.profit / b.weight;
  }

  double findMaxProfit() {
    sort(items.begin(), items.end(), cmp);

    double maxProfit = 0.0;

    for (int i = 0; i < n; i++) {
      if (items[i].weight <= W) {
        maxProfit += items[i].profit;
        W -= items[i].weight;
      } else {
        maxProfit += W * ((double)items[i].profit / items[i].weight);
        break;
      }
    }
    return maxProfit;
  }
};

int main() {
  vector<Item> items = {
      Item(100, 2),
      Item(19, 1),
      Item(27, 2),
      Item(25, 1),
      Item(15, 3)};

  Knapsack kn(items, 5);
  cout << "Maximum Profit: " << kn.findMaxProfit() << endl;

  return 0;
}
