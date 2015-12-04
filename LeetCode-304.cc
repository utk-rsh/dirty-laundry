class NumMatrix {
private:
  vector<vector<int>> precomputed;
public:
    NumMatrix(vector<vector<int>> &matrix)
    {
      precomputed = matrix;
      if (precomputed.size() == 0)
        return;
      for (int i = 0; i < precomputed.size(); i++)
        for (int j = 1; j < precomputed[0].size(); j++)
        {
            precomputed[i][j] += precomputed[i][j-1];
        }
      for (int i = 1; i < precomputed.size(); i++)
        for (int j = 0; j < precomputed[0].size(); j++)
          precomputed[i][j] += precomputed[i-1][j];
      return;
    }

    int sumRegion(int row1, int col1, int row2, int col2) 
    {
      int region1 = precomputed[row2][col2];
      int region2 = (row1 > 0 ? precomputed[row1 - 1][col2] : 0);
      int region3 = (col1 > 0 ? precomputed[row2][col1 - 1] : 0);
      int region4 = ((row1 > 0) && (col1 > 0)) ? precomputed[row1 - 1][col1 - 1] : 0;
      return region1 - region2 - region3 + region4;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);