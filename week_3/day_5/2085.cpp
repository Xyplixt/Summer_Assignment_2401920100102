#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  int countWords(vector<string> &words1, vector<string> &words2) {
    int result = 0;
    unordered_map<string, int> mp;
    for (string s : words1) {
      if (!mp[s]) {
        mp[s]++;
      } else {
        mp[s] = 10;
      }
    }
    for (string s : words2) {
      if (mp[s] == 1) {
        mp[s]++;
      } else if (mp[s] == 2) {
        mp[s] = 10;
      }
    }
    for (auto m : mp) {
      if (m.second == 2) {
        result++;
      }
    }
    return result;
  }
};
