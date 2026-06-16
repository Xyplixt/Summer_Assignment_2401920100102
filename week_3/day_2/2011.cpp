#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  int finalValueAfterOperations(vector<string> &operations) {
    int count = 0;
    for (string &s : operations) {
      if (s.find('+') != string::npos) {
        count++;
      } else {
        count--;
      }
    }
    return count;
  }
};
