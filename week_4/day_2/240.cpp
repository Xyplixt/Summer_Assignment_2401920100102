#include <vector>
using namespace std;
class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int colm = matrix[0].size() - 1;
    int left = 0, right = colm, mid = 0;
    while (left <= right) {
      mid = left + (right - left) / 2;
      if (target < matrix[0][mid]) {
        right = mid - 1;
      } else if (target > matrix[0][mid]) {
        left = mid + 1;
      } else {
        return true;
      }
    }
    int l = 0, r = matrix.size() - 1, m = 0;
    while (l <= r) {
      m = l + (r - l) / 2;
      if (matrix[m][mid] > target) {
        r = m - 1;
      } else if (matrix[m][mid] < target) {
        l = m + 1;
      }
    }
    return (matrix[m][mid] == target);
  }
};
