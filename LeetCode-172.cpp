#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n)
    {
      long long ans = 0;
      long long div = 5;
      long long number = n;
      while (number/div > 0)
      {
        ans += number/div;
        div = 5*div;
      }
      return (int)ans;
    }
};
