#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x)
    {
      long long ul = 2147483647;
      long long ll = 2147483648;
      ll = -1LL*ll;
      long long input = x;
      bool negative = (x < 0);
      long long ans = 0;
      while (x != 0)
      {
        long long digit = x % 10;
        x = x / 10;
        ans = ans*10 + digit;
      }
      if (ans > ul)
        return 0;
      if (ans < ll)
        return 0;
      return ans;
    }
};

int main()
{
  Solution obj;
  int ans = obj.reverse(-123);
  cout << ans << endl;
  return 0;
}
