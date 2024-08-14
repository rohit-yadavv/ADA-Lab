// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card


#include <algorithm>

struct Item {
    int value;
    int weight;
};

class Solution {
  public:
    static bool cmp(Item a, Item b) {
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }

    double fractionalKnapsack(int W, Item arr[], int n) {
        std::sort(arr, arr + n, cmp);

        double totalValue = 0.0;

        for (int i = 0; i < n; i++) {
            if (W >= arr[i].weight) {
                totalValue += arr[i].value;
                W -= arr[i].weight;
            } else {
                totalValue += arr[i].value * ((double)W / arr[i].weight);
                break;
            }
        }

        return totalValue;
    }
};
