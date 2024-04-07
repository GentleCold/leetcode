#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
private:
  vector<vector<string>> ans;
  vector<string> sample;
  vector<vector<int>> table;

  void put(pair<int, int> a, int flag) {
    for (int i = 0; i < table.size(); ++i) {
      table[a.first][i] += flag;
      table[i][a.second] += flag;
    }

    // for (int i = a.first, j = a.second; i >= 0 && j >= 0; --i, --j) {
    //   table[i][j] += flag;
    // }

    for (int i = a.first, j = a.second; i < table.size() && j < table.size();
         ++i, ++j) {
      table[i][j] += flag;
    }

    // for (int i = a.first, j = a.second; i >= 0 && j < table.size(); --i, ++j) {
    //   table[i][j] += flag;
    // }

    for (int i = a.first, j = a.second; i < table.size() && j >= 0; ++i, --j) {
      table[i][j] += flag;
    }
  }

  void backtrace(int row, int n) {
    if (sample.size() == n) {
      ans.push_back(sample);
    }

    if (row == n) {
      return;
    }

    for (int j = 0; j < n; ++j) {
      if (table[row][j] == false) {

        string s = "";
        for (int i = 0; i < n; ++i) {
          if (i == j) {
            s += "Q";
          } else {
            s += ".";
          }
        }
        sample.push_back(s);

        put({row, j}, 1);
        backtrace(row + 1, n);
        put({row, j}, -1);
        sample.pop_back();
      }
    }
  }

public:
  vector<vector<string>> solveNQueens(int n) {
    vector<int> row(n, 0);
    for (int i = 0; i < n; ++i) {
      table.push_back(row);
    }

    backtrace(0, n);

    return ans;
  }
};
