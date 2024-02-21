class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if (!head)
      return nullptr;
    auto slow = head, fast = head;
    while (true) {
      slow = slow->next;
      fast = fast->next;

      if (fast) {
        fast = fast->next;
      } else
        return nullptr;

      if (!fast)
        return nullptr;

      if (slow == fast) {
        auto p = head;
        while (p != slow) {
          p = p->next;
          slow = slow->next;
        }
        return p;
      }
    }
  }
};
