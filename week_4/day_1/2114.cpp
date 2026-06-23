#include <sstream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  int mostWordsFound(vector<string> &sentences) {
    int maxm = 0;
    for (string &s : sentences) {
      int count = 1;
      for (char &c : s) {
        if (c == ' ') {
          count++;
        }
      }
      maxm = max(maxm, count);
    }
    return maxm;
  }
};
