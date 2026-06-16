#include <cstdlib>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  int countKDifference(vector<int> &nums, int k) {
    int result = 0;
    unordered_map<int, int> mp;
    for (int n : nums) {
      mp[n]++;
    }
    for (int n : nums) {
      if (mp[n - k]) {
        result += mp[n - k];
      }
      if (mp[n + k]) {
        result += mp[n + k];
      }
      mp[n]--;
    }
    return result;
  }
};
