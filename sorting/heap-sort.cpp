#include <iostream>
#include <vector>
using namespace std;

class Heap {
 private:
  vector<int> heap;

  void heapify(int n, int i) {
    int largest = i;        // Initialize largest as root
    int left = 2 * i + 1;   // Left child
    int right = 2 * i + 2;  // Right child

    // If left child is larger than root
    if (left < n && heap[left] > heap[largest])
      largest = left;

    if (right < n && heap[right] > heap[largest])
      largest = right;

    // If largest is not root
    if (largest != i) {
      swap(heap[i], heap[largest]);
      heapify(n, largest);
    }
  }

 public:
  Heap(const vector<int>& input) {
    this->heap = input;
  }

  void heapSort() {
    int n = heap.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
      heapify(n, i);
    }

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
      swap(heap[0], heap[i]);  // Move current root to the end
      heapify(i, 0);           // Call heapify on the reduced heap
    }
  }

  void printHeap() const {
    for (int val : heap) {
      cout << val << " ";
    }
    cout << endl;
  }
};

// Driver code
int main() {
  vector<int> input = {12, 11, 13, 5, 6, 7};
  Heap h(input);

  cout << "Original array: ";
  h.printHeap();

  h.heapSort();

  cout << "Sorted array: ";
  h.printHeap();

  return 0;
}
