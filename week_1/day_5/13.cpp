#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<char, int> roman = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                                  {'C', 100}, {'D', 500}, {'M', 1000}};
class Solution {
public:
  int romanToInt(string s) {
    int result = 0;
    int prev = 0;
    for (int i = int(s.size()) - 1; i >= 0; i--) {
      if (roman[s[i]] >= prev) {
        result += roman[s[i]];
      } else {
        result -= roman[s[i]];
      }
      prev = roman[s[i]];
    }
    return result;
  }
};
int main() {
  Solution rom;
  cout << rom.romanToInt("MCMXCIV");
  return 0;
}
