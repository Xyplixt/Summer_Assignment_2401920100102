#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  int countConsistentStrings(string allowed, vector<string> &words) {
    int result = words.size();
    unordered_map<char, bool> mp;
    for (char &a : allowed) {
      mp[a] = true;
    }
    for (string &s : words) {
      for (char &c : s) {
        if (!mp[c]) {
          result--;
          break;
        }
      }
    }
    return result;
  }
};
int main() {
  Solution sol;
  string allowed = "ab";
  vector<string> words = {"ad", "bd", "aaab", "baa", "badab"};
  cout << sol.countConsistentStrings(allowed, words);
  return 0;
}
