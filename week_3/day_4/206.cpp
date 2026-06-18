#include <vector>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    vector<int> vec;
    ListNode *temp = head;
    while (temp != nullptr) {
      vec.emplace_back(temp->val);
      temp = temp->next;
    }
    ListNode *temp1 = head;
    for (int i = vec.size() - 1; i >= 0; i--) {
      temp1->val = vec[i];
      temp1 = temp1->next;
    }
    return head;
  }
};
