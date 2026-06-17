#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  bool isHappy(int n) {
    int num = 0;
    int r = 0;
    for (int i = 0; i < 7; i++) {
      while (n != 0) {
        r = n % 10;
        n /= 10;
        num += r * r;
      }
      n = num;
      num = 0;
      if (n == 1)
        return true;
    }
    return false;
  }
};
