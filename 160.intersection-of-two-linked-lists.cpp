class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    auto a = headA, b = headB;

    while (1) {
      if (a == b) {
        return a;
      }

      if (!a)
        a = headB;
      else
        a = a->next;

      if (!b)
        b = headA;
      else
        b = b->next;
    }
  }
};
