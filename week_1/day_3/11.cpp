#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  int maxArea(vector<int> &height) {
    int start = 0, end = height.size() - 1, maxArea = 0;
    ;
    while (start < end) {
      if (height[start] < height[end]) {
        int area = (end - start) * height[start];
        if (maxArea < area)
          maxArea = area;
        start++;
      } else {
        int area = (end - start) * height[end];
        if (maxArea < area)
          maxArea = area;
        end--;
      }
    }
    return maxArea;
  }
};
