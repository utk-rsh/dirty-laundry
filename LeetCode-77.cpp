#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

class Solution {
public:

    void recur(vector<vector<int> > &ans, vector<int> &current, int n, int remaining, int index)
    {
      if (remaining == 0)
      {
        ans.push_back(current);
        return;
      }
      if (index > n)
      {
        return;
      }
      for (int i = index; i <= n; i++)
      {
        current.push_back(i);
        recur(ans, current, n, remaining - 1, i + 1);
        current.pop_back();
      }
      return;
    }

    vector<vector<int> > combine(int n, int k)
    {
        vector<int> current;
        vector<vector<int> > ans;
        recur(ans, current, n, k, 1);
        return ans;
    }
};

int main()
{
  Solution obj;
  vector<vector<int> > ans = obj.combine(4,2);
  cout << "Size of output is " << ans.size() << endl;
  cout << ans[0][0] << " " << ans[0][1] << endl;
  cout << ans[1][0] << " " << ans[1][1] << endl;
  cout << ans[2][0] << " " << ans[2][1] << endl;
  return 0;
}
