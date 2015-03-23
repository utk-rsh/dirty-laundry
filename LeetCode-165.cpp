#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2)
    {
      version1 = version1 + ".0";
      version2 = version2 + ".0";
      while ((version1.find(".") != -1) || (version2.find(".") != -1))
      {
        int index1 = version1.find(".");
        int index2 = version2.find(".");
        string sub1 = version1.substr(0, index1);
        string sub2 = version2.substr(0, index2);
        int v1 = atoi(sub1.c_str());
        int v2 = atoi(sub2.c_str());
        if (v1 > v2)
          return 1;
        if (v1 < v2)
          return -1;
        version1 = version1.substr(index1 + 1);
        version2 = version2.substr(index2 + 1);
      }
      int swapped = 1;
      if (version1.find(".") == -1)
      {
        string temp = version1;
        version1 = version2;
        version2 = temp;
        swapped = -1;
      }
      while (version1.find(".") != -1)
      {
        int index1 = version1.find(".");
        string sub1 = version1.substr(0, index1);
        int v1 = atoi(sub1.c_str());
        if (v1 != 0)
          return swapped*1;
        version1 = version1.substr(index1 + 1);
      }
      int v1 = atoi(version1.c_str());
      if (v1 != 0)
        return swapped*1;
      return 0;
    }
};

int main()
{
  string in1 = "1";
  string in2 = "0";
  int index = in1.find(".");
  Solution obj;
  int ans = obj.compareVersion(in1, in2);
  cout << "ans is " << ans << endl;
  return 0;
}
