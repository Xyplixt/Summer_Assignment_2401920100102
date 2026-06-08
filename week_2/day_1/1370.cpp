#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  string sortString(string s) {
    vector<int> ch(26, 0);
    string result = "";
    for (char c : s) {
      ch[c - 'a']++;
    }

    while (result.size() != s.size()) {
      // smallest
      for (int i = 0; i < ch.size(); i++) {
        if (ch[i] != 0) {
          result += char(i + 'a');
          ch[i]--;
        }
      }

      // largest
      for (int i = ch.size() - 1; i >= 0; i--) {
        if (ch[i] != 0) {
          result += char(i + 'a');
          ch[i]--;
        }
      }
    }
    return result;
  }
};
