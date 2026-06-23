#include <algorithm>
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
  bool isPalindrome(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    // finding the middle of the LL
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    // reversing after middle part
    ListNode *prev = nullptr;
    while (slow) {
      ListNode *front = slow->next;
      slow->next = prev;
      prev = slow;
      slow = front;
    }
    ListNode *left = head;
    ListNode *right = prev;
    // comparing the left and right part
    while (right) {
      if (left->val != right->val)
        return false;
      left = left->next;
      right = right->next;
    }
    return true;
  }
};
