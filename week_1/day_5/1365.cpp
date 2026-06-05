#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
    vector<int> result;
    for (int i : nums) {
      int count = 0;
      for (int j : nums) {
        if (i > j)
          count++;
      }
      result.push_back(count);
    }
    return result;
  }
};
