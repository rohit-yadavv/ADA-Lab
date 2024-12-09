#include <bits/stdc++.h>
using namespace std;

void selectionSortRecursive(int arr[], int n, int index) {
  if (index == n) return;

  int minIndex = index;
  for (int i = index + 1; i < n; i++) {
    if (arr[i] < arr[minIndex]) {
      minIndex = i;
    }
  }
  swap(arr[minIndex], arr[index]);

  selectionSortRecursive(arr, n, index + 1);
}

int main() {
  int arr[] = {64, 25, 12, 22, 11};
  int n = sizeof(arr) / sizeof(arr[0]);

  selectionSortRecursive(arr, n, 0);

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}
