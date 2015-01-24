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
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        vector<int> ans;
        if (m == 0)
            return ans;
        int n = matrix[0].size();
        int top = 1;
        int left = 0;
        int right = n-1;
        int bottom = m-1;
        int counter = 1;
        int x = 0;
        int y = 0;
        cout << m*n << " ... " << endl;
        while (counter <= m*n)
        {
     //       cout << "Right is " << right << endl;
            while(y <= right)
            {
     //           cout << "x is " << x << " y is " << y << " and counter is " << counter << endl;
                ans.push_back(matrix[x][y]);
                counter++;
                y++;
            }
            if (counter > m*n)
                break;
            x++;
            y--;
            right--;
       //     cout << "Bottom is " << bottom << endl;
            while (x <= bottom)
            {
           //     cout << "x is " << x << " y is " << y << " and counter is " << counter << endl;
                ans.push_back(matrix[x][y]);
                counter++;
                x++;
            }
            if (counter > m*n)
                break;
            x--;
            y--;
            bottom--;
         //   cout << "Left is " << left << endl;
            while (y >= left)
            {
       //         cout << "x is " << x << " y is " << y << " and counter is " << counter << endl;
                ans.push_back(matrix[x][y]);
                counter++;
                y--;
            }
            if (counter > m*n)
                break;
            y++;
            x--;
            left++;
     //       cout << "Top is " << top << endl;
            while (x >= top)
            {
    //            cout << "x is " << x << " y is " << y << " and counter is " << counter << endl;
                ans.push_back(matrix[x][y]);
                counter++;
                x--;
            }
            y++;
            x++;
            top++;
        }
        return ans;
    }
};

\
