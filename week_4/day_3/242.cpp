#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  bool isAnagram(string s, string t) {
    vector<int> vec(26, 0);
    unordered_map<char, int> mp;
    for (char c : s) {
      vec[c - 'a']++;
    }
    for (char c : t) {
      vec[c - 'a']--;
    }
    for (int v : vec) {
      if (v) {
        return false;
      }
    }
    return true;
  }
};
