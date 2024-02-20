class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    auto dummyhead = new ListNode(0, head);
    auto cur = dummyhead;
    while (cur->next) {
      auto first = cur->next;
      auto second = cur->next->next;
      if (!second)
        break;

      first->next = second->next;
      second->next = first;
      cur->next = second;
      cur = first;
    }

    return dummyhead->next;
  }
};
