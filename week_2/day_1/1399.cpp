#include <unordered_map>
using namespace std;
class Solution {
public:
  int countLargestGroup(int n) {
    unordered_map<int, int> mp;
    int result = 0;
    int prev = 0;
    for (int i = 1; i <= n; i++) {
      int j = i;
      int sum = 0;
      int r = 0;
      while (j != 0) {
        r = j % 10;
        sum += r;
        j /= 10;
      }
      mp[sum]++;
      if (mp[sum] > prev) {
        prev = mp[sum];
        result = 1;
      } else if (mp[sum] == prev) {
        result++;
      }
    }
    return result;
  }
};
