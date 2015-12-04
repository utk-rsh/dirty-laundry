class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
{
  if (matrix.size() == 0)
    return 0;
  vector<vector<int>> mat;
  vector<int> temp;
  temp.resize(matrix[0].size());
  for (int i = 0; i < matrix.size(); i++)
  {
    for (int j = 0; j < matrix[0].size(); j++)
    {
      temp[j] = matrix[i][j] - '0';
    }
    mat.push_back(temp);
  }
  for (int i = 1; i < matrix.size(); i++)
  {
    for (int j = 1; j < matrix[0].size(); j++)
    {
      if (mat[i][j] == 1)
      {
        mat[i][j] = min(min(mat[i-1][j-1], mat[i-1][j]), mat[i][j-1]) + 1;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < matrix.size(); i++)
    for (int j = 0; j < matrix[0].size(); j++)
      if (mat[i][j] > ans)
        ans = mat[i][j];
 // cout << "max element is " << ans << endl;  
  return (ans)*(ans);
}
};