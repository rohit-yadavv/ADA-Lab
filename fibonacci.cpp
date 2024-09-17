#include <iostream>
#include <vector>
using namespace std;

int fibbo(int n, std::vector<int>& memo) {
  if (n == 0) return 0;
  if (n == 1) return 1;

  if (memo[n] != -1) {
    return memo[n];
  }

  memo[n] = fibbo(n - 1, memo) + fibbo(n - 2, memo);
  return memo[n];
}

int main() {
  int n = 9;
  vector<int> memo(n + 1, -1);
  cout << "Fibonacci number at position " << n << " is " << fibbo(n, memo) << std::endl;
  return 0;
}
