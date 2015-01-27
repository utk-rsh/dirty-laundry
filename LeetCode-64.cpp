#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid)
    {
        vector<vector<int>> memo = grid;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (i == 0 && j == 0)
                    continue;
                else if (i == 0)
                    grid[i][j] = grid[i][j-1] + grid[i][j];
                else if (j == 0)
                    grid[i][j] = grid[i-1][j] + grid[i][j];
                else
                    grid[i][j] = min(grid[i-1][j],grid[i][j-1]) + grid[i][j];
            }
        }
        if (grid.size() == 0)
            return 0;
        return grid[grid.size()-1][grid[0].size()-1];
    }
};
