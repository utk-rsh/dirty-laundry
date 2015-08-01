#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

class Solution {
public:
    int rob(vector<int> &num)
    {
      if (num.size() == 0)
        return 0;
      int a0 = num[0];
      if (num.size() == 1)
        return a0;
      int a1 = num[1];
      for (int i = 2; i < num.size(); i++)
      {
        int temp = a1;
        a1 = max(a0 + num[i], a1);
        a0 = max(a0, temp);
      }
      return max(a0, a1);
    }
};
