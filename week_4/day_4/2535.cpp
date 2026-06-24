#include <cstdlib>
#include <vector>
using namespace std;
class Solution {
public:
  int differenceOfSum(vector<int> &nums) {
    int elementSum = 0;
    int digitsSum = 0;
    for (int &i : nums) {
      elementSum += i;
      while (i > 0) {
        digitsSum += i % 10;
        i /= 10;
      }
    }
    return abs(digitsSum - elementSum);
  }
};
