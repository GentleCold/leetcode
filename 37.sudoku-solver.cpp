#include <utility>
#include <vector>
using namespace std;

class Solution {
private:
  bool valid(vector<vector<char>> &board, const pair<int, int> &pos,
               char num) {
    for (int i = 0; i < 9; ++i) {
      if (board[pos.first][i] == num || board[i][pos.second] == num) {
        return false;
      }
    }

    // 0 1 2 3 4 5 6 7 8
    int base_i = (pos.first / 3) * 3;
    int base_j = (pos.second / 3) * 3;
    for (int i = base_i; i < base_i + 3; ++i) {
      for (int j = base_j; j < base_j + 3; ++j) {
        if (board[i][j] == num) {
          return false;
        }
      }
    }

    return true;
  }

  bool backtrace(vector<vector<char>> &board, const pair<int, int> &pos) {
    pair<int, int> next = pos;
    while (board[next.first][next.second] != '.') {
      ++next.first;
      if (next.first == 9) {
        next.first = 0;
        ++next.second;
        if (next.second == 9) {
          return true;
        }
      }
    }

    for (int i = 1; i <= 9; ++i) {
      if (valid(board, next, '0' + i)) {
        board[next.first][next.second] = '0' + i;
        if (backtrace(board, next))
          return true;
        board[next.first][next.second] = '.';
      }
    }

    return false;
  }

public:
  void solveSudoku(vector<vector<char>> &board) { backtrace(board, {0, 0}); }
};
