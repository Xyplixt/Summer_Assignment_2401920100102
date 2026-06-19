#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
  int countPoints(string rings) {
    unordered_map<string, int> mp;
    int n = rings.size();
    int result = 0;
    for (int i = 1; i < n; i += 2) {
      if ((mp[to_string(rings[i]) + 'R'] == 0) && rings[i - 1] == 'R') {
        mp[to_string(rings[i]) + 'R']++;
      } else if ((mp[to_string(rings[i]) + 'G'] == 0) && rings[i - 1] == 'G') {
        mp[to_string(rings[i]) + 'G']++;
      } else if ((mp[to_string(rings[i]) + 'B'] == 0) && rings[i - 1] == 'B') {
        mp[to_string(rings[i]) + 'B']++;
      }
      if (mp[to_string(rings[i]) + 'R'] >= 1 &&
          mp[to_string(rings[i]) + 'G'] >= 1 &&
          mp[to_string(rings[i]) + 'B'] >= 1) {
        mp[to_string(rings[i]) + 'B'] = -500;
        result += 1;
      }
    }
    return result;
  }
};
int main() {
  Solution sol;
  sol.countPoints("B9G5G5B4R4");
  return 0;
}
