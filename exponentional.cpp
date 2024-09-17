#include <iostream>
#include <vector>
using namespace std;

class Exponential {
 private:
  vector<int> memo;

 public:
  int findPowerUsingInefficientIteration(int a, int b) {
    int result = 1;
    for (int i = 1; i <= b; i++)
      result *= a;

    return result;
  }

  int findPowerUsingInefficientRecursion(int a, int b) {
    if (b == 0) {
      return 1;
    }
    return a * findPowerUsingInefficientRecursion(a, b - 1);
  }

  int findPowerUsingEfficientIteration(int a, int b) {
    if (b == 0) return 1;
    int ans = 1;

    while (b >= 1) {
      if (b % 2 != 0) {
        ans *= a;
      }
      a *= a;
      b /= 2;
    }
    return ans;
  }

  int findPowerUsingEfficientRecursion(int a, int b) {
    if (b == 0) {
      return 1;
    }

    int ans = findPowerUsingEfficientRecursion(a, b / 2);
    ans *= ans;

    if (b % 2 != 0) {
      ans *= a;
    }
    return ans;
  }

  int findPowerUsingMemoization(int a, int b) {
    if (memo.size() < b + 1) {
      memo.resize(b + 1, -1);
    }
    if (b == 0) {
      return 1;
    }
    if (memo[b] != -1) {
      return memo[b];
    }

    int ans = findPowerUsingMemoization(a, b / 2);
    ans *= ans;

    if (b % 2 != 0) {
      ans *= a;
    }
    memo[b] = ans;
    return ans;
  }
};

int main() {
  Exponential check;
  cout << "Using Inefficient Iteration: " << check.findPowerUsingInefficientIteration(2, 10) << endl;
  cout << "Using Optimized Iteration: " << check.findPowerUsingEfficientIteration(2, 10) << endl;
  cout << "Using Inefficient Recursion: " << check.findPowerUsingInefficientRecursion(2, 10) << endl;
  cout << "Using Optimized Recursion: " << check.findPowerUsingEfficientRecursion(2, 10) << endl;
  cout << "Using Memoization: " << check.findPowerUsingMemoization(2, 10) << endl;
}