#include <bits/stdc++.h>
using namespace std;

class NQueen {
 private:
  int n;
  vector<vector<string>> solutions;
  vector<string> board;

  bool isSafe(int row, int col, vector<string>& board) {
    for (int i = 0; i < row; i++) {
      if (board[i][col] == 'q') {
        return false;
      }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
      if (board[i][j] == 'q') {
        return false;
      }
    }

    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
      if (board[i][j] == 'q') {
        return false;
      }
    }

    return true;
  }

  void solve(int row) {
    if (row == n) {
      solutions.push_back(board);
      return;
    }
    for (int col = 0; col < n; col++) {
      if (isSafe(row, col, board)) {
        board[row][col] = 'q';
        solve(row + 1);
        board[row][col] = '.';
      }
    }
  }

 public:
  NQueen(int n) {
    this->n = n;
    board.resize(n, string(n, '.'));
  }

  vector<vector<string>> findAllSolutions() {
    solve(0);
    return solutions;
  }
};

int main() {
  int n;
  cout << "Enter the value of N: ";
  cin >> n;

  NQueen nQueen(n);
  vector<vector<string>> solutions = nQueen.findAllSolutions();

  cout << "Total solutions: " << solutions.size() << endl;
  for (const auto& solution : solutions) {
    for (const auto& row : solution) {
      cout << row << endl;
    }
    cout << endl;
  }

  return 0;
}
