#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
  int canBeTypedWords(string text, string brokenLetters) {
    int result = 1;
    bool valid = true;
    for (char c : text) {
      if (c == ' ')
        result++;
    }
    unordered_set<char> mp;
    for (char c : brokenLetters) {
      mp.insert(c);
    }
    for (char c : text) {
      if (c == ' ') {
        valid = true;
      }
      if (mp.count(c) && valid) {
        result--;
        valid = false;
      }
    }
    return result;
  }
};
