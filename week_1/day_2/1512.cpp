#include <vector>
using namespace std;
class Solution {
public:
  int numIdenticalPairs(vector<int> &nums) {
    short int result = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[i] == nums[j]) {
          result++;
        }
      }
    }
    return result;
  }
};
