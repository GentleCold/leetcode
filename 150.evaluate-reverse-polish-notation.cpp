#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> s;
    for (const auto &token : tokens) {
      if (token == "+" || token == "-" || token == "*" || token == "/") {
        int r = s.top();
        s.pop();
        int l = s.top();
        s.pop();
        int ans = 0;

        switch (token[0]) {
        case '+':
          ans = l + r;
          break;
        case '*':
          ans = l * r;
          break;
        case '-':
          ans = l - r;
          break;
        case '/':
          ans = l / r;
          break;
        }

        s.push(ans);
      } else {
        s.push(stoi(token));
      }
    }
    return s.top();
  }
};
