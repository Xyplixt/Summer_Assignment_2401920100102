#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    for (int i = 0; i < (int)nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[i] + nums[j] == target) {
          vector<int> result;
          result.push_back(i);
          result.push_back(j);
          return result;
        }
      }
    }
    return {};
  }
};
int main() {
  Solution res;
  vector<int> nums = {2, 3, 4, 5, 6};
  int target = 9;
  vector<int> ans = res.twoSum(nums, target);
  cout << ans[0] << endl << ans[1];
  return 0;
}
