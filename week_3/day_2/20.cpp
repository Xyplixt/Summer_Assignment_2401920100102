#include <stack>
#include <string>
using namespace std;
class Solution {
public:
  bool isValid(string s) {
    stack<char> stk;
    for (char c : s) {
      if (c == '[' || c == '(' || c == '{') {
        stk.push(c);
      } else {
        if (!stk.empty() && (stk.top() == c - 1 || stk.top() == c - 2)) {
          stk.pop();
        } else
          return false;
      }
    }
    if (!stk.empty()) {
      return false;
    }
    return true;
  }
};
