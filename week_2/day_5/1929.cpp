#include <vector>
using namespace std;
class Solution {
public:
  vector<int> getConcatenation(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(2 * n);
    int k = 0;
    for (int j = 0; j < 2; j++) {
      for (int i = 0; i < n; i++) {
        ans[k++] = nums[i];
      }
    }
    return ans;
  }
};
