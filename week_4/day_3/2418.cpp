#include <algorithm>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> sortPeople(vector<string> &names, vector<int> &heights) {
    vector<string> result;
    unordered_map<int, string> mp;
    for (int i = 0; i < heights.size(); i++) {
      mp[heights[i]] = names[i];
    }
    sort(heights.begin(), heights.end(), greater<int>());
    for (int &height : heights) {
      result.push_back(mp[height]);
    }
    return result;
  }
};
