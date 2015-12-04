class Solution {
public:
  void recur(vector<vector<int>> &ans, vector<int> &current, int value, int k, int n)
  {
    if (k == 0)
    {
      if (n == 0)
      {
          ans.push_back(current);
          return;
      }
      return;
    }
    if (n < 0)
      return;
    for (int i = value + 1; i <= 9; i++)
    {
      current.push_back(i);
      recur(ans, current, i, k-1, n-i);
      current.pop_back();
     }
     return;
  }

  vector<vector<int>> combinationSum3(int k, int n) 
  {
    vector<vector<int>> ans;
    vector<int> current;
    recur(ans, current, 0, k, n);
    return ans;   
  }
};
