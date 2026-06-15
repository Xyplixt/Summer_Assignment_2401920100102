#include <string>
using namespace std;
class Solution {
public:
  int getLucky(string s, int k) {
    int result = 0;
    for (char c : s) {
      int temp = ((c - 'a' + 1) % 10) + ((c - 'a' + 1) / 10);
      result += temp;
    }
    k--;
    while (k != 0) {
      int temp = 0;
      while (result != 0) {
        int r = result % 10;
        temp += r;
        result /= 10;
      }
      result = temp;
      k--;
    }
    return result;
  }
};
