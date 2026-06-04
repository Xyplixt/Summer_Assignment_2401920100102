#include <iostream>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  bool uniqueOccurrences(vector<int> &arr) {
    unordered_map<int, int> mp;
    unordered_set<int> st;
    int result = 0;
    for (int i : arr) {
      mp[i]++;
    }
    for (auto m : mp) {
      st.insert(m.second);
    }
    return (mp.size() == st.size());
  }
};
int main() {
  int res = 0;
  for (int i = 1; i < 59; i++) {
    res ^= i;
  }
  cout << res;
  return 0;
}
