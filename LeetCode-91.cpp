#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int numDecodings(string s)
    {
      if ((s == "") || (s[0] == '0'))
        return 0;
      int found = s.find("10");
      while (found != -1)
      {
        s.erase(found, 2);
        found = s.find("10");
      }
      found = s.find("20");
      while (found != -1)
      {
        s.erase(found, 2);
        found = s.find("20");
      }
      if (s == "")
        return 1;
      if (s[0] == '0')
        return 0;
      int *arr = new int[s.length()];
      memset(arr, 0, s.length()*sizeof(int));
      arr[0] = 1;
      for (int i = 1; i < s.length(); i++)
      {
        int val = (s[i] - '0') + (s[i-1] -'0')*10;
        if ((s[i] == '0') && ((s[i-1] > '2') || (s[i-1] == '0')))
          return 0;
        else if (s[i] == '0')
        {
          arr[i] = arr[i-1] - 1;
        }
        else if (val == 0)
          return 0;
        else if ((val > 26))
          arr[i] = arr[i-1];
        else
          arr[i] = arr[i-1] + arr[max(0, i-2)];
      }
      return arr[s.length() - 1];
    }
};


int main()
{
  string test = "100";
  Solution obj;
  int ans = obj.numDecodings(test);
  cout << "Ans is " << ans << endl;
  return 0;
}
