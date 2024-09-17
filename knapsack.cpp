#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Item {
 public:
  string name;
  double weight;
  double profit;

  Item(string name, double weight, double profit) {
    this->name = name;
    this->weight = weight;
    this->profit = profit;
  }
};

class FractionalKnapsack {
 private:
  int capacity;
  vector<Item> arr;
  int n;

  static bool cmp(Item a, Item b) {
    double r1 = a.profit / a.weight;
    double r2 = b.profit / b.weight;
    return r1 > r2;
  }

 public:
  FractionalKnapsack(int capacity, vector<Item>& items) {
    this->capacity = capacity;
    this->arr = items;
    this->n = items.size();
  }

  double findMaxProfit() {
    sort(arr.begin(), arr.end(), cmp);
    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
      if (capacity >= arr[i].weight) {
        totalValue += arr[i].profit;
        capacity -= arr[i].weight;
      } else {
        totalValue += arr[i].profit * ((double)capacity / arr[i].weight);
        break;
      }
    }
    return totalValue;
  }
};

int main() {
  vector<Item> items = {Item("Item1", 10, 60), Item("Item2", 20, 100), Item("Item3", 30, 120)};

  int capacity = 50;
  FractionalKnapsack f(capacity, items);

  cout << "Max profit: " << f.findMaxProfit() << endl;

  return 0;
}
