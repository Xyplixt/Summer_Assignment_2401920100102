#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> separateDigits(vector<int> &nums) {
    vector<int> ans;

    for (int &x : nums) {
      for (char &c : to_string(x))
        ans.push_back(c - '0');
    }

    return ans;
  }
};
