#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

class Solution {
public:
    void flow(vector<vector<char> > &grid, int x, int y)
    {
      if (x >= grid.size())
        return;
      if (y >= grid[0].size())
        return;
      if (x < 0 || y < 0)
        return;
      if (grid[x][y] == '1')
        grid[x][y] = 'S';
      else
        return;
      flow(grid, x+1, y);
      flow(grid, x, y+1);
      flow(grid, x-1, y);
      flow(grid, x, y-1);
      return;
    }

    int numIslands(vector<vector<char> > &grid)
    {
      int ans = 0;
      for (int i = 0; i < grid.size(); i++)
      {
        for (int j = 0; j < grid[0].size(); j++)
        {
          if (grid[i][j] == '1')
          {
            ans++;
            flow(grid, i, j);
          }
        }
      }
      return ans;
    }
};
