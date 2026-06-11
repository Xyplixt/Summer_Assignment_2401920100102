#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  int countBalls(int lowLimit, int highLimit) {
    vector<int> vec(46, 0);
    int result = 0;
    for (int i = lowLimit; i <= highLimit; i++) {
      int j = i;
      int box = 0;
      while (j != 0) {
        box += j % 10;
        j /= 10;
      }
      vec[box]++;
      result = max(result, vec[box]);
    }
    return result;
  }
};
