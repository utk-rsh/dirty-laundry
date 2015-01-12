#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <stack>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target)
    {
        int index = matrix.size() -1;
        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][0] > target)
            {
                index = i - 1;
                break;
            }
        }
 //       cout << "index is " << index << endl;
//        cout << "first element is " << binary_search(matrix[index].begin(), matrix[index].end(), 1) << endl;
        if (index == -1)
            return false;
        else
            return binary_search(matrix[index].begin(), matrix[index].end(), target);
    }
};

int main()
{
vector< vector<int> > test;
vector<int> mini;
mini.push_back(1);
test.push_back(mini);
cout << "Binary test is " << binary_search(test[0].begin(), test[0].end(), 1) << endl;
Solution a;
cout << a.searchMatrix(test, 1);
return 0;
}

