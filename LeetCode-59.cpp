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
    vector<vector<int> > generateMatrix(int n)
    {
        vector<vector<int>> ans;
        vector<int> dummy (n);
        for (int i = 0; i < n; i++)
            dummy[i] = 0;
        for (int i = 0; i < n; i++)
            ans.push_back(dummy);
        int top = 1;
        int left = 0;
        int right = n-1;
        int bottom = n-1;
        int counter = 1;
        int x = 0;
        int y = 0;
        while (counter <= n*n)
        {
     //       cout << "Right is " << right << endl;
            while(y <= right)
            {
     //           cout << "x is " << x << " y is " << y << " and counter is " << counter << endl;
                ans[x][y] = counter;
                counter++;
                y++;
            }
            x++;
            y--;
            right--;
     //       cout << "Bottom is " << bottom << endl;
            while (x <= bottom)
            {
     //           cout << "x is " << x << " y is " << y << " and counter is " << counter << endl;
                ans[x][y] = counter;
                counter++;
                x++;
            }
            x--;
            y--;
            bottom--;
     //       cout << "Left is " << left << endl;
            while (y >= left)
            {
     //           cout << "x is " << x << " y is " << y << " and counter is " << counter << endl;
                ans[x][y] = counter;
                counter++;
                y--;
            }
            y++;
            x--;
            left++;
    //        cout << "Top is " << top << endl;
            while (x >= top)
            {
    //            cout << "x is " << x << " y is " << y << " and counter is " << counter << endl;
                ans[x][y] = counter;
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
