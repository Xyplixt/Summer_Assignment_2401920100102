#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// I was declaring the map in here .. global .. thus it was storing data between
// FUNCTION CALLS

// unordered_map<int, int> mp;
class Solution {
public:
  unordered_map<int, int> mp;
  bool containsDuplicate(vector<int> &nums) {
    for (int i = 0; i < (int)nums.size(); i++) {
      if (mp.count(nums[i])) {
        return true;
      } else {
        mp[nums[i]] = i;
      }
    }
    return false;
  }
};
int main() {
  vector<int> nums = {1, 2, 3, 4};
  Solution chk;
  cout << chk.containsDuplicate(nums);
  return 0;
}
