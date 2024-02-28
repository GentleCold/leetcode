#include <stack>
class MyQueue {
public:
  MyQueue() {}

  void push(int x) {
    std::stack<int> tmp;
    while (!s.empty()) {
      tmp.push(s.top());
      s.pop();
    }
    tmp.push(x);
    while (!tmp.empty()) {
      s.push(tmp.top());
      tmp.pop();
    }
  }

  int pop() {
    auto i = s.top();
    s.pop();
    return i;
  }

  int peek() { return s.top(); }

  bool empty() { return s.empty(); }

private:
  std::stack<int> s;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
