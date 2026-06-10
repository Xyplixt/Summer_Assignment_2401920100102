#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  int majorityElement(vector<int> &nums) {
    unordered_map<int, int> mp;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      mp[nums[i]]++;
      if (mp[nums[i]] > n / 2) {
        return nums[i];
      }
    }
    return {};
  }
};
int main() {
  vector<int> nums = {1, 2, 3, 1, 1};
  Solution sol;
  cout << sol.majorityElement(nums);
  return 0;
}
