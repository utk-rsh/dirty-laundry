#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix)
    {
      int tr_x = 0;
      int tr_y = 0;
      int n = matrix.size();
      n = n - 1;
      while (tr_x <= n/2)
      {
        while (try_y < n - tr_x)
        {
          int temp = matrix[tr_y][n - tr_x];
          matrix[tr_y][n - tr_x] = matrix[tr_x][tr_y];
          matrix[tr_x][tr_y] = matrix[n-tr_y][tr_x];
          matrix[n - tr_y][tr_x] = matrix[n - tr_x][n-tr_y];
          matrix[n-tr_x][n - tr_y] = temp;
          tr_y++;
        }
        tr_x++;
        tr_y = tr_x;
      }
      return matrix;
    }
};
