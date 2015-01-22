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
    int uniquePaths(int m, int n)
    {
        int memo[m][n];
        memset(memo, 0, sizeof(int)*m*n);
        cout << "Check " << memo[m-1][n-1] << endl;
        for (int i = 0; i < n; i++)
            memo[0][i] = 1;
        for (int i = 0; i < m; i++)
            memo[i][0] = 1;
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
   //             cout << "prev two are " << memo[i-1][j] << " and " << memo[i][j-1] << endl;
                memo[i][j] = memo[i-1][j] + memo[i][j-1];
   //             cout << "i is " << i << " j is " << j << " and memo value is " << memo[i][j] << endl;
            }
        }
        return memo[m-1][n-1];
    }
};
