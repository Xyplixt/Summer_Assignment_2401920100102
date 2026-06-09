#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int maxE = nums[0], minE = nums[0], ans = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] < 0)
        swap(minE, maxE);
      maxE = max(nums[i], nums[i] * maxE);
      minE = min(nums[i], nums[i] * minE);
      ans = max(ans, maxE);
    }
    return ans;
  }
};
