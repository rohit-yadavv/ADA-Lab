#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
  int largest = i;
  int left = 2 * i;
  int right = 2 * i + 1;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  if (largest != i) {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

void heapSort(int arr[], int n) {
  int size = n;
  while (size > 1) {
    swap(arr[size], arr[1]);
    size--;
    heapify(arr, size, 1);
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

// Driver code
int main() {
  int arr[] = {12, 11, 13, 5, 6, 7};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Original array: ";
  printArray(arr, n);

  heapSort(arr, n);

  cout << "Sorted array: ";
  printArray(arr, n);

  return 0;
}
