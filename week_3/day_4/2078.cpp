// there will always be an endpoint included so use two pointers
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  int maxDistance(vector<int> &colors) {
    int mx1 = 0, mx2 = 0;
    int n = colors.size();
    int left = 0, right = n - 1;
    while (left < right) {
      if (colors[left] == colors[right]) {
        right--;
      } else {
        break;
      }
    }
    mx1 = right - left;
    left = 0, right = n - 1;
    while (left < right) {
      if (colors[left] == colors[right]) {
        left++;
      } else {
        break;
      }
    }
    mx2 = right - left;
    return max(mx1, mx2);
  }
};
