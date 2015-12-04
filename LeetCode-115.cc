class Solution {
public:
  int dp(string &s, string &t, int i, int j, vector<vector<int>> &cache)
  {
    if (i == s.length())
      return 0;
    if (cache[i][j] != -1)
      return cache[i][j];
    int temp = -1;
    if (s[i] == t[j])
      temp = dp(s,t,i+1,j+1,cache) + dp(s,t,i+1,j,cache);
    else
      temp = dp(s,t,i+1,j,cache);
    cache[i][j] = temp;
    return temp;
  }

  int numDistinct(string s, string t)
  {
    if (s == t)
      return 1;
    if (s.length() == 0)
      return 0;
    if (t.length() == 0)
      return 1;
    vector<vector<int>> cache;
    vector<int> row;
    row.resize(t.length());
    fill(row.begin(), row.end(), -1);
    for (int i = 0; i < s.length(); i++)
      cache.push_back(row);
    int counter = 0;
    for (int i = (int)s.length() - 1; i > -1; i--)
    {
      if (s[i] == t[t.length() - 1])
        counter++;
      cache[i][t.length()-1] = counter;
    }
    dp(s,t,0,0,cache);
    return cache[0][0];
  }
};