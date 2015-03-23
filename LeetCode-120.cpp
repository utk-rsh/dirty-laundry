#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void recur(vector<vector<int> > &triangle, int i, int j, vector<vector<int> > &memo)
    {
      //cout << "i j are " << i << " " << j << " and memo is " << memo[i][j] << endl;
      if (j == 0)
        {
          memo[i][j] = memo[i][j] + memo[i-1][j];
        }
      else if (j == triangle[i].size() - 1)
        {
          memo[i][j] += memo[i-1][j-1];
        }
      else if ((j > 0) && (j < triangle[i].size() - 1))
        {
          memo[i][j] += min(memo[i-1][j], memo[i-1][j-1]);
        }
      //cout << "modified memo is " << memo[i][j] << endl;
      return;
    }

    int minimumTotal(vector<vector<int> > &triangle)
    {
      vector<vector<int> > memo;
      memo = triangle;
      for (int i = 1; i < triangle.size(); i++)
      {
        for (int j = 0; j < triangle[i].size(); j++)
        {
          recur(triangle, i, j, memo);
        }
      }
      int row = triangle.size();
      int col = triangle[row-1].size();
      int ans = memo[row-1][0];
      for (int i = 0; i < triangle[row-1].size(); i++)
      {
         ans = min(ans, memo[row-1][i]);
      //  cout << "answer comparision with " << memo[row-1][i] << endl;
      }
      return ans;
    }
};

int main()
{
  vector<vector<int> > triangle;
  vector<int> test;
  test.push_back(-1);
  triangle.push_back(test);
  test.clear();
  test.push_back(2);
  test.push_back(3);
  triangle.push_back(test);
  test.clear();
  test.push_back(1);
  test.push_back(-1);
  test.push_back(-3);
  triangle.push_back(test);
  Solution obj;
  int ans = obj.minimumTotal(triangle);
  cout << "Ans is " << ans << endl;
}
