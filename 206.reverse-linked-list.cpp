class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (!head)
      return nullptr;
    ListNode *prev = head;
    ListNode *cur = head->next;
    head->next = nullptr;

    while (cur) {
      auto tmp = cur;
      cur = tmp->next;
      tmp->next = prev;
      prev = tmp;
    }
    return prev;
  }
};
