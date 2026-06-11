#include <vector>
using namespace std;
class Solution {
public:
  bool check(vector<int> &nums) {
    int count = 0;
    int prev = nums[0];
    int first_start = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] < prev) {
        count++;
        if (count == 2) {
          return false;
        }
        int second_start = nums[i];
        if (first_start < second_start) {
          return false;
        }
      }
      prev = nums[i];
    }
    if (count == 1 && first_start < nums[nums.size() - 1]) {
      return false;
    }
    return true;
  }
};
