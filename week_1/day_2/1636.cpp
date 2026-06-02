#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> frequencySort(vector<int> &nums) {
    vector<int> result;
    unordered_map<int, int> mp;
    for (int n : nums) {
      mp[n]++;
    }
    sort(nums.begin(), nums.end(), [&](int a, int b) {
      if (mp[a] == mp[b])
        return a > b;
      else
        return mp[a] < mp[b];
    });
    return nums;
  }
};
