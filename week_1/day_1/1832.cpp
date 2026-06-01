#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  bool checkIfPangram(string sentence) {
    unordered_set<char> st = {sentence.begin(), sentence.end()};
    if (st.size() == 26)
      return true;
    else
      return false;
  }
};
