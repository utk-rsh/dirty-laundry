class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) 
  {
    if (matrix.size() == 0)
      return false;
    int start = matrix[0].size() - 1;
    for (int i = 0; i < matrix.size(); i++)
    {
      if (matrix[i][start] == target)
        return true;
      bool flag = 0;
      while (start > -1 && matrix[i][start] > target)
      {
        start--;
        flag = 1;
        if (start < 0)
          break;
        if (matrix[i][start] == target)
          return true;
      }
      if (flag)
        start++;
    }
    return false;
  }
};

