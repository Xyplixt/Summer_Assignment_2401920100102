#include <iostream>;
#include <vector>
using namespace std;
class Solution {
public:
  int subsetXORSum(vector<int> &nums) {
    int n = nums.size(), sum = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
      int temp = 0;
      for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
          temp ^= nums[i];
        }
      }
      sum += temp;
    }
    return sum;
  }
};
int main() {
  Solution sol;
  vector<int> nums = {3, 4, 5, 6, 7, 8};
  cout << sol.subsetXORSum(nums);
  return 0;
}
