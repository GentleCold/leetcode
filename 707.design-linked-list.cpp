class Node {
public:
  int val = 0;
  Node *next = nullptr;

  Node() = default;
  explicit Node(int val) : val(val) {}
};

class MyLinkedList {
public:
  MyLinkedList() {}

  int get(int index) {
    auto cur = head;
    while (cur && index >= 0) {
      --index;
      cur = cur->next;
    }
    if (!cur || cur == head)
      return -1;
    else
      return cur->val;
  }

  void addAtHead(int val) {
    auto node = new Node(val);
    node->next = head->next;
    head->next = node;
  }

  void addAtTail(int val) { // O(n)
    auto node = new Node(val);
    auto cur = head;
    while (cur->next) {
      cur = cur->next;
    }
    cur->next = node;
  }

  void addAtIndex(int index, int val) {
    auto cur = head;
    while (index > 0 && cur) {
      --index;
      cur = cur->next;
    }

    if (cur) {
      auto node = new Node(val);
      node->next = cur->next;
      cur->next = node;
    }
  }

  void deleteAtIndex(int index) {
    auto cur = head;
    while (index > 0 && cur) {
      --index;
      cur = cur->next;
    }
    if (cur) {
      auto tmp = cur->next;
      if (tmp)
        cur->next = tmp->next;
      else
        cur->next = nullptr;
      delete tmp;
    }
  }

private:
  Node *head = new Node();
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
