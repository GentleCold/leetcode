
class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    auto dummyhead = new ListNode(0, head);
    auto first = dummyhead, second = head;

    while (--n) {
      second = second->next;
    }

    while (second->next) {
      first = first->next;
      second = second->next;
    }

    first->next = first->next->next; // remind to delete
    return dummyhead->next;
  }
};
