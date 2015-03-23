#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class ValueOfString
{
public:
    int findValue(string s)
    {
      int ans = 0;
      for (int i = 0; i < s.length(); i++)
      {
        int smaller = 0;
        for (int j = 0; j < s.length(); j++)
        {
          if (s[j] <= s[i])
            smaller++;
        }
        ans += smaller*(s[i] - 'a' + 1);
      }
      return ans;
    }
};
