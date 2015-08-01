#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>

using namespace std;

class Solution {
public:
    string pal(string s, int index)
    {
      string ans = "";
      int i = 1;
      int length = 1;
      while (index - i >= 0 && index + i < s.length())
      {
        if (s[index - i] != s[index + i])
          break;
        else
          length += 2;
        i++;
      }
      ans = s.substr(index - (length - 1)/2, length);
      i = 0;
      length = 0;
      while (index - i >= 0 && index + 1 + i  < s.length())
      {
        if (s[index - i] != s[index + 1 + i])
          break;
        else
          length += 2;
        i++;
      }
      string temp = s.substr(index - (length - 2)/2, length);
      if (temp.length() > ans.length())
        ans = temp;
      return ans;
    }

    string longestPalindrome(string s)
    {
      string ans = "";
      for (int i = 0; i < s.length(); i++)
      {
        string temp =  pal(s,i);
        if (temp.length() > ans.length())
          ans = temp;
      }
      return ans;
    }
};
