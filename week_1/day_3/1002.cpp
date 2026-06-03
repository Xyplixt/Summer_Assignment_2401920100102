#include <climits>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  vector<string> commonChars(vector<string> &words) {
    vector<string> result;
    vector<int> freq(26, 0);
    vector<int> high(26, INT_MAX);
    for (string s : words) {
      for (char c : s) {
        freq[c - 'a']++;
      }
      for (int i = 0; i < 26; i++) {
        high[i] = min(high[i], freq[i]);
      }
      // NOTE:
      // wrong way to make all elements 0 in vectorj
      // freq = {0};
      // correct way
      fill(freq.begin(), freq.end(), 0);
    }

    for (int i = 0; i < 26; i++) {
      while (high[i] > 0) {
        result.push_back(string(1, 'a' + i));
        high[i]--;
      }
    }

    return result;
  }
};
