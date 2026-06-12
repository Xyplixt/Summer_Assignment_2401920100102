#include <vector>
using namespace std;
class Solution {
public:
  int arraySign(vector<int> &nums) {
    bool bt = false;
    for (int &i : nums) {
      if (i == 0)
        return 0;
      else if (i < 0)
        bt = !bt;
    }
    if (bt) {
      return -1;
    }
    return 1;
  }
};
