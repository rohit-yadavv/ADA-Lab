// #include <iostream>
// #include <vector>
// using namespace std;
// class ExponentiationDP {
// public:
//     ExponentiationDP(int maxExp) : memo(maxExp + 1, -1) {}
//     int power(int x, int n) {
//         if (n == 0) return 1; 
//         if (memo[n] != -1) return memo[n]; 

//         if (n % 2 == 0) {
//             int half = power(x, n / 2);
//             memo[n] = half * half;
//         } else {
//             memo[n] = x * power(x, n - 1);
//         }
//         return memo[n];
//     }

// private:
//     vector<int> memo; 
// };

// int main() {
//     int x = 2;
//     int n = 10;
//     ExponentiationDP dp(n);
//     cout << x << "^" << n << " = " << dp.power(x, n) <<endl;
//     return 0;
// }



#include <iostream>
#include <vector>
using namespace std;
class ExponentiationDP {
public:
    int power(int x, int n) {
        if (n == 0) return 1;  
        vector<int> dp(n + 1, 0);
        dp[0] = 1;  
        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 0) {
                int half = dp[i / 2];
                dp[i] = half * half;
            } else {
                dp[i] = x * dp[i - 1];
            }
        }
        return dp[n];
    }
};

int main() {
    int x = 2;
    int n = 10;
    ExponentiationDP dp;
    cout << x << "^" << n << " = " << dp.power(x, n) <<endl;
    return 0;
}
