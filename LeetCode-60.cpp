#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <sstream>

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

class Solution {
private:
  int fact[100];
public:
    int factorial(int n)
    {
      if (n == 0)
        return 1;
      if (fact[n] != 0)
        return fact[n];
      fact[n] = n*factorial(n-1);
      return fact[n];
    }

    string getPermutation(int n, int k)
    {
      memset(fact, 0, 100*sizeof(int));
      int *digits = new int[100];
      memset(digits, 0, 100*sizeof(int));
      digits[0] = 1;
      string ans = "";
      while (ans.length() < n)
      {
        int f = factorial(n - ans.length() - 1);
        int d = k/f;
        int e = k % f;
        if (e != 0)
          d++;
        int c = 0;
        for (int i = 0; i < n+1; i++)
        {
          if (digits[i] == 0)
            c++;
          if (c == d)
          {
            digits[i] = 1;
            c = i;
            break;
          }
        }
        ans += SSTR(c);
        e != 0 ? k = e : k = f;
      }
      return ans;
    }
};

int main()
{
  Solution obj;
  string ans = obj.getPermutation(4, 11);
  cout << "Ans is " << ans << endl;
  return 0;
}
