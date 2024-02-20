#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  ListNode *removeElements(ListNode *head, int val) {
    while (head && head->val == val) {
      auto tmp = head;
      head = head->next;
      delete tmp;
    }

    auto cur = head;

    while (cur) {
      if (cur->next && cur->next->val == val) {
        auto tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
      } else
        cur = cur->next;
    }
    return head;
  }
};
