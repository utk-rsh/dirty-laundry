class Solution {
public:
bool check(vector<pair<int, int>> &pos, int row, int col)
{
  for (int i = 0; i < pos.size(); i++)
  {
      if (pos[i].first == row)
        return false;
      if (pos[i].second == col)
        return false;
      if (pos[i].first - pos[i].second == row - col)
        return false;
      if (pos[i].first + pos[i].second == row + col)
        return false;
  }
  return true;
}

void recur(int &ans, vector<pair<int, int>> &current, int ql, int row, int dim)
{
  if (ql == 0)
  {
     ans++;
     return;
  }
  if (ql + row > dim)
    return;
  for (int i = 0; i <  dim; i++)
  {
    if (check(current, row, i))
    {
      current.push_back(make_pair(row,i));
      recur(ans, current, ql - 1, row + 1, dim);
      current.pop_back();
    }
  }
  return;
}

int solution(int dim)
{
  int ans;
  vector<pair<int, int>> current;
  recur(ans, current, dim, 0, dim);
  return ans;
}

    int totalNQueens(int n) {
        return solution(n);     
    }
};