#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs)
    {
      vector<pair<string, string>> groups;
      vector<string> ans;
      for (int i = 0; i < strs.size(); i++)
      {
        string temp = strs[i];
        sort(temp.begin(), temp.end());
        groups.push_back(make_pair(temp, strs[i]));
      }
      sort(groups.begin(), groups.end());
      for (int i = 1; i < groups.size(); i++)
      {
        if (groups[i].first == groups[i-1].first)
        {
          if (ans.size() != 0)
          {
            if (ans.back() != groups[i-1].second)
              ans.push_back(groups[i-1].second);
          }
          else
            ans.push_back(groups[i-1].second);
          ans.push_back(groups[i].second);
        }
      }
      return ans;
    }
};
