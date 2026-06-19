#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  string firstPalindrome(vector<string> &words) {
    for (string &s : words) {
      int start = 0, end = s.size() - 1;
      while (start < end) {
        if (s[start] != s[end]) {
          break;
        }
        start++;
        end--;
      }
      return s;
    }
    return "";
  }
};
