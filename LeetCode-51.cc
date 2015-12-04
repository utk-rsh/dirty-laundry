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

void recur(vector<vector<pair<int,int>>> &ans, vector<pair<int, int>> &current, int ql, int row, int dim)
{
  if (ql == 0)
  {
     ans.push_back(current);
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

vector<vector<pair<int, int>>> solution(int dim)
{
  vector<vector<pair<int, int>>> ans;
  vector<pair<int, int>> current;
  recur(ans, current, dim, 0, dim);
  return ans;
}

vector<vector<string>> printer(int dim)
{
  auto config = solution(dim);
  vector<vector<string>> ans;
  vector<string> small;
  string single = "";
  for (int i = 0; i < dim; i++)
    single += ".";
  for (int i = 0; i < dim; i++)
    small.push_back(single);
  for (int i = 0; i < config.size(); i++)
  {
    for (int j = 0; j < config[i].size(); j++)
    {
      small[config[i][j].first][config[i][j].second] = 'Q';
    }
    ans.push_back(small);
    for (int j = 0; j < config[i].size(); j++)
    {
      small[config[i][j].first][config[i][j].second] = '.';
    }
  }
  return ans;
}

    vector<vector<string>> solveNQueens(int n) {
        return printer(n);        
    }
};