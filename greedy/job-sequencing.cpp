#include <bits/stdc++.h>
using namespace std;

class Jobs {
 public:
  int id;
  int profit;
  int deadline;

  Jobs(int id, int profit, int deadline) {
    this->id = id;
    this->profit = profit;
    this->deadline = deadline;
  }
};

class JobSequencing {
 private:
  vector<Jobs> jobs;
  int n;

 public:
  JobSequencing(vector<Jobs> jobs) {
    this->jobs = jobs;
    this->n = jobs.size();
  }

  static bool cmp(Jobs a, Jobs b) {
    return a.profit > b.profit;
  }

  int findJobsWithMaxProfit() {
    sort(jobs.begin(), jobs.end(), cmp);

    vector<bool> slot(n, false);
    int maxProfit = 0;

    for (int i = 0; i < n; i++) {
      for (int j = min(jobs[i].deadline - 1, n - 1); j >= 0; j--) {
        if (!slot[j]) {
          maxProfit += jobs[i].profit;
          slot[j] = true;
          break;
        }
      }
    }

    return maxProfit;
  }
};

int main() {
  vector<Jobs> jobs = {
      Jobs(1, 100, 2),
      Jobs(2, 19, 1),
      Jobs(3, 27, 2),
      Jobs(4, 25, 1),
      Jobs(5, 15, 3)};

  JobSequencing js(jobs);
  cout << "Maximum Profit: " << js.findJobsWithMaxProfit() << endl;

  return 0;
}
