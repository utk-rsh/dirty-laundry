#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void recurse(vector<string> *ans, int left, int right, int buffer, string current)
    {
      if (buffer < 0)
        return;
      if (right == 0)
      {
        ans->push_back(current);
        return;
      }
      if (left != 0)
      {
        current += "(";
        recurse(ans, left - 1, right, buffer + 1, current);
        current.pop_back();
      }
      current += ")";
      recurse(ans, left, right - 1, buffer - 1, current);
      current.pop_back();
      return;

    }

    vector<string> generateParenthesis(int n)
    {
      vector<string> ans;
      string current = "";
      recurse(&ans, n, n, 0, current);
      return ans;
    }
};
