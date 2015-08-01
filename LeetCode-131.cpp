#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

class Solution {
public:
    bool checkp (string *a)
    {
      string b = *a;
      reverse(b.begin(), b.end());
      return b == *a;
    }

    void recur(vector<vector<string> > *ans, vector<string> *current, string s, int low, int high)
    {
      if (high >= s.length())
        return;
      string temp = s.substr(low, high - low + 1);
      recur(ans, current, s, low, high + 1);
      if (checkp(&temp))
      {
        current->push_back(temp);
        if (high == s.length() - 1)
          ans->push_back(*current);
        recur(ans, current, s, high + 1, high + 1);
        current->pop_back();
      }
      return;
    }

    vector<vector<string> > partition(string s)
    {
      vector<vector<string> > ans;
      vector<string> c;
      recur(&ans, &c, s, 0, 0);
      return ans;
    }
};

int main()
{
  string a = "aab";
  Solution obj;
  vector<vector<string> > ans = obj.partition(a);
  cout << "size of ans " << ans.size() << endl;
  return 0;
}
