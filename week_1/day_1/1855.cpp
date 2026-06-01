#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  int maxDistance(vector<int> &nums1, vector<int> &nums2) {
    int point1 = 0;
    int point2 = 0;
    int mx = 0;
    while (point1 < nums1.size() && point2 < nums2.size()) {
      if (nums1[point1] <= nums2[point2]) {
        mx = max(point2 - point1, mx);
        point2++;

      } else {
        point1++;
        if (point1 > point2)
          point2 = point1;
      }
    }

    return mx;
  }
};
