#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  int countVowelSubstrings(string word) {
    int result = 0;
    for (int i = 0; i < word.size(); i++) {
      unordered_map<char, int> mp;
      int count = 0;
      for (int j = i + 1; j < word.size(); j++) {
        if (word[i] != 'a' && word[i] != 'e' && word[i] != 'i' &&
            word[i] != 'o' && word[i] != 'u')
          break;
        mp[word[i]]++;
        count++;
        if (word[j] != 'a' && word[j] != 'e' && word[j] != 'i' &&
            word[j] != 'o' && word[j] != 'u')
          break;
        mp[word[j]]++;
        count++;
        if (count >= 5 && mp['a'] && mp['e'] && mp['i'] && mp['o'] && mp['u']) {
          result++;
        }
      }
    }
    return result;
  }
};
int main() {
  Solution sol;
  string word = "aeiouu";
  cout << sol.countVowelSubstrings(word);
  return 0;
}
