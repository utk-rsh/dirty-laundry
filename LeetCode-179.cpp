#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;


bool compare_lt(int a, int b)
{
  string first = to_string(a) + to_string(b);
  string second = to_string(b) + to_string(a);
  return first < second;
}


class Solution {
public:
  string largestNumber(vector<int> &num)
  {
    sort(num.begin(), num.end(), compare_lt);
    if (num.size() == 0)
      return "";
    string ans = "";
    for (int i = num.size() - 1; i > - 1; i--)
    {
    //  cout << "i is " << i << " and adding element " << num[i] << endl;
      ans += to_string(num[i]);
    }
    if (ans[0] == '0')
      return "0";
    return ans;
  }
};

int main()
{
  vector<int> input = {8308, 830};
  bool t = compare_lt(121, 12);
  cout << "OUTPUT OF COMPARISION IS " << t << endl << endl;
  Solution obj;
  string ans = obj.largestNumber(input);
  cout << "Output ans is " << ans << endl;
  return 0;
}
