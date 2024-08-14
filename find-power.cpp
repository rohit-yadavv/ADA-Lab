#include <iostream>
using namespace std;

// brute force O(n)
int power(int a, int b){
  int result=1;
  for (int i = 1; i <= b; i++) 
    result *= a;
  
  return result;
}

// O(log n)
int powerR(int a, int b){
  if (b == 0)
    return 1;

  int ans = powerR(a, b / 2);
  ans *= ans;

  if (b % 2 != 0)
    ans *= a;

  return ans;
}

// O(log n)
int powerI(int a, int b){
  if(b==0) return 1;
  int ans = 1;

  while(b >= 1){
    if(b%2 != 0){
      ans*=a;
    }
    
    a*=a;
    b/=2;
  }
  return ans;
}

int main(){
  cout << power(2, 5) << endl;
  cout << powerR(2, 5)<<endl;
  cout << powerI(2, 5)<<endl;
  return 0;
}
