#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  string reverseWords(string s) {
    vector<string> str;
    string result = "";
    stringstream ss(s);
    string word;
    while (ss >> word) {
      str.push_back(word);
    }
    for (string &s : str) {
      if (result == "")
        result.insert(0, s);
      else {
        result.insert(0, s + " ");
      }
    }
    return result;
  }
};
int main() {
  Solution sol;
  cout << sol.reverseWords(
      "this     is                                              great string");
  return 0;
}
