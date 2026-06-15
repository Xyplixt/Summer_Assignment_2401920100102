#include <iostream>
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *temp1 = l1;
    ListNode *temp2 = l2;
    ListNode *dummy = new ListNode(0);
    ListNode *curr = dummy;
    int charge = 0;
    while (temp1 != nullptr || temp2 != nullptr || charge) {
      int sum = 0;
      if (temp1 != nullptr) {
        sum += temp1->val;
        temp1 = temp1->next;
      }
      if (temp2 != nullptr) {
        sum += temp2->val;
        temp2 = temp2->next;
      }
      sum += charge;
      curr->next = new ListNode(sum % 10);
      curr = curr->next;
      charge = sum / 10;
    }
    return dummy->next;
  }
};

int main() {
  // create first list: 2 -> 4 -> 3
  ListNode *l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);

  // create second list: 5 -> 6 -> 4
  ListNode *l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);

  // call your function
  Solution obj;
  ListNode *result = obj.addTwoNumbers(l1, l2);

  // print result list
  while (result != nullptr) {
    cout << result->val << " ";
    result = result->next;
  }

  return 0;
}
