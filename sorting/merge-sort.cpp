#include <bits/stdc++.h>
using namespace std;

int merge(int arr[], int low, int mid, int high) {
  int tempArr[high - low + 1];
  int left = low;
  int right = mid + 1;
  int index = 0;

  while (left <= mid && right <= high) {
    if (arr[left] < arr[right]) {
      tempArr[index] = arr[left];
      left++;
    } else {
      tempArr[index] = arr[right];
      right++;
    }
    index++;
  }
  while (left <= mid) {
    tempArr[index] = arr[left];
    left++;
    index++;
  }
  while (right <= high) {
    tempArr[index] = arr[right];
    right++;
    index++;
  }
  for (int i = 0; i < index; i++) {
    arr[low + i] = tempArr[i];
  }
}

int mergeSort(int arr[], int low, int high) {
  if (low < high) {
    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
  }
}

int main() {
  int arr[] = {23, 4, 45, 67, 6};
  mergeSort(arr, 0, 4);
  for (int i = 0; i < 5; i++)
    cout << arr[i] << ", ";
  return 0;
}
