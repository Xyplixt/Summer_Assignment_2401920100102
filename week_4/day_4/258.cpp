#include <iostream>
using namespace std;
class Solution {
public:
  int addDigits(int num) {
    int n = 0;
    while (num > 9) {
      while (num != 0) {
        int r = num % 10;
        n += r;
        num /= 10;
      }
      num = n;
      n = 0;
    }
    return num;
  }
};
int main() {
  Solution sol;
  cout << sol.addDigits(0);
  return 0;
}
