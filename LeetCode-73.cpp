#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

#define INT_MAX 2,147,483,647
using namespace std;

class Solution {
public:
    void fil(vector<vector<int>> *matrix, int ff, int i, int j)
    {
        int xlength = matrix->size();
        int ylength = (*matrix)[0].size();
        (*matrix)[i][j] = ff;
        for (int t1 = 0; t1 < ylength; t1++)
        {
            if ((*matrix)[i][t1] == 0)
                fil(matrix, ff, i, t1);
            (*matrix)[i][t1] = ff;
        }
        for (int t1 = 0; t1 < xlength; t1++)
        {
            if ((*matrix)[t1][j] == 0)
                fil(matrix, ff, t1, j);
            (*matrix)[t1][j] = ff;
        }
        return;
    }

    void setZeroes(vector<vector<int> > &matrix)
    {
        int missing = -3;
        bool flag = 1;
        while (flag)
        {
            missing++;
            flag = 0;
            for (int i = 0; i < matrix.size(); i++)
            {
                for (int j = 0; j < matrix[0].size(); j++)
                {
                    if (matrix[i][j] == missing)
                        flag = 1;
                }
            }
        }
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    fil(&matrix, missing, i, j);
                }
            }
        }
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == missing)
                    matrix[i][j] = 0;
            }
        }
        return;
    }
};

int main()
{
vector<vector<int>> test;
vector<int> push;
push.push_back(0);push.push_back(0);push.push_back(0);push.push_back(5);
test.push_back(push);
push.clear();
push.push_back(4);push.push_back(3);push.push_back(1);push.push_back(4);
test.push_back(push);
push.clear();
push.push_back(0);push.push_back(1);push.push_back(1);push.push_back(4);
test.push_back(push);
push.clear();
push.push_back(1);push.push_back(2);push.push_back(1);push.push_back(3);
test.push_back(push);
push.clear();
push.push_back(0);push.push_back(0);push.push_back(1);push.push_back(1);
test.push_back(push);
Solution obj;
obj.setZeroes(test);
cout << "test 1 2 is " << test[1][2] << endl;
return 0;
}
