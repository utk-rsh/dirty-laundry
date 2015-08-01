#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

class Solution {
public:
    void flow(vector<vector<char> > &board, int i, int j)
    {
      queue<pair<int, int> > q;
      q.push(make_pair(i, j));
      while (q.empty() == 0)
      {
    //    cout << "iii: " << q.front().first << "  jjj: " << q.front().second << endl;
        if (board[q.front().first][q.front().second] == 'O')
        {
    //      cout << "i: " << q.front().first << "  j: " << q.front().second << endl;
          board[q.front().first][q.front().second] = '1';
          if (q.front().first < board.size() - 1)
            q.push(make_pair(q.front().first + 1, q.front().second));
          if (q.front().first > 0)
            q.push(make_pair(q.front().first - 1, q.front().second));
          if (q.front().second < board[0].size() - 1)
            q.push(make_pair(q.front().first, q.front().second + 1));
          if (q.front().second > 0)
            q.push(make_pair(q.front().first, q.front().second - 1));
        }
        q.pop();
      }
      return;
    }

    void solve(vector<vector<char> > &board)
    {
      int rows = board.size();
      if (rows == 0)
        return;
      int cols = board[0].size();
      for (int i = 0; i < cols; i++)
      {
        if (board[0][i] == 'O')
          flow(board, 0, i);
        if (board[rows - 1][i] == 'O')
          flow(board, rows - 1, i);
      }
      for (int i = 0; i < rows; i++)
      {
        if (board[i][0] == 'O')
          flow(board, i, 0);
        if (board[i][cols - 1] == 'O')
          flow(board, i, cols - 1);
      }
      for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
          if (board[i][j] == 'O')
            board[i][j] = 'X';
          if (board[i][j] == '1')
            board[i][j] = 'O';
        }
      return;
    }
};

int main()
{
  vector<vector<char> > myb;
  vector<char> t;
  t.push_back('X');
  t.push_back('X');
  t.push_back('X');
  t.push_back('O');
  t.push_back('O');
  t.push_back('O');
  t.push_back('O');
  t.push_back('O');
  t.push_back('O');
  t.push_back('O');
  t.push_back('O');
  t.push_back('O');
  t.push_back('X');
  myb.push_back(t);
  t[1] = 'O';
  t[5] = 'X';
  myb.push_back(t);
  t[4] = 'X';
  t[5] = 'O';
  t[6] = 'X';
  t[1] = 'X';
  myb.push_back(t);
  t[5] = 'X';
  t[1] = 'O';
  myb.push_back(t);
  for (int i = 0; i < myb.size(); i++)
  {
    for (int j = 0; j < myb[0].size(); j++)
    {
      cout << myb[i][j] << " ";
    }
    cout << endl;
  }
  cout << "THIS WAS THE BOARD BEFORE" << endl << endl;
  Solution obj;
  obj.solve(myb);
  for (int i = 0; i < myb.size(); i++)
  {
    for (int j = 0; j < myb[0].size(); j++)
    {
      cout << myb[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
