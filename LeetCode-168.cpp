#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    string convertToTitle(int n)
    {
      string ans = "";
      while (n > 0)
      {
        ans += ((n - 1) % 26) + 'A';
        n = (n - 1) / 26;
      }
      reverse(ans.begin(), ans.end());
      return ans;
    }
};
