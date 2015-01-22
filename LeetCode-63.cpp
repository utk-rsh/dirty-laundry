#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <bitset>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
    {
        int m = obstacleGrid.size();
        if ( m == 0)
            return 0;
        int n = obstacleGrid[0].size();
        int memo[m][n];
        memset(memo, 0, sizeof(int)*m*n);
        for (int i = 0; i < n; i++)
        {
            if (obstacleGrid[0][i] == 1)
                break;
            memo[0][i] = 1;
        }
        for (int i = 0; i < m; i++)
        {
            if (obstacleGrid[i][0] == 1)
                break;
            memo[i][0] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] != 1)
                    memo[i][j] = memo[i-1][j] + memo[i][j-1];
            }
        }
       return memo[m-1][n-1];
    }
};
