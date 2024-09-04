#include<iostream>
#include<vector>
#include<string>

class Item {
public:
    std::string name;
    double weight;
    double profit;
    double profitPerWeight;

    Item(std::string name, double weight, double profit)
        : name(name), weight(weight), profit(profit) {
        profitPerWeight = profit / weight;
    }
};

// Function to merge two halves of the array
void merge(std::vector<Item>& items, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<Item> L(n1);
    std::vector<Item> R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = items[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = items[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].profitPerWeight >= R[j].profitPerWeight) {
            items[k++] = L[i++];
        } else {
            items[k++] = R[j++];
        }
    }

    while (i < n1) {
        items[k++] = L[i++];
    }

    while (j < n2) {
        items[k++] = R[j++];
    }
}

// Merge sort function
void mergeSort(std::vector<Item>& items, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(items, left, mid);
        mergeSort(items, mid + 1, right);

        merge(items, left, mid, right);
    }
}

double fractionalKnapsack(std::vector<Item>& items, double capacity) {
    // Sort items based on profit per weight using merge sort
    mergeSort(items, 0, items.size() - 1);

    double totalProfit = 0.0;
    double remainingCapacity = capacity;

    for (const auto& item : items) {
        if (remainingCapacity == 0) break;

        if (item.weight <= remainingCapacity) {
            // Take the whole item
            totalProfit += item.profit;
            remainingCapacity -= item.weight;
        } else {
            // Take the fraction of the item
            totalProfit += item.profitPerWeight * remainingCapacity;
            remainingCapacity = 0;
        }
    }

    return totalProfit;
}

int main() {
    std::vector<Item> items = {
        Item("Item1", 10, 60),
        Item("Item2", 20, 100),
        Item("Item3", 30, 120)
    };

    double capacity = 50;
    double maxProfit = fractionalKnapsack(items, capacity);

    std::cout << "Maximum profit that can be obtained: " << maxProfit << std::endl;

    return 0;
}