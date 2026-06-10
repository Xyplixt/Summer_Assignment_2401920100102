#include <vector>
using namespace std;
class Solution {
public:
  int maximumWealth(vector<vector<int>> &accounts) {
    int result = 0;
    for (vector<int> &v : accounts) {
      int count = 0;
      for (int &i : v) {
        count += i;
      }
      result = max(count, result);
    }
    return result;
  }
};
