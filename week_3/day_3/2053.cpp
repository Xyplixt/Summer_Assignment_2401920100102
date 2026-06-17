#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  string kthDistinct(vector<string> &arr, int k) {
    unordered_map<string, int> mp;
    vector<string> result;
    for (string r : arr) {
      mp[r]++;
    }
    for (string r : arr) {
      if (mp[r] == 1) {
        result.push_back(r);
      }
    }
    return result.size() < k ? "" : result[k - 1];
  }
};
