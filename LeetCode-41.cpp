#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

class Solution {
public:
  int firstMissingPositive(int A[], int n)
  {
    if (n == 0)
      return 1;
    else if ((n == 1) && (A[0] == 1))
      return 2;
    else if ((n == 1) && (A[0] != 1))
      return 1;
    int on_n = 0;
    for (int i = 0; i < n; i++)
      A[i] = 2*A[i];
    for (int i = 0; i < n; i++)
    {
      if ((A[i]/2 < n) && (A[i]/2 > 0))
      {
        if (A[A[i]/2] % 2 == 0)
          A[A[i]/2]++;
      }
      if (A[i]/2 == n)
        on_n = 1;
    }
    for (int i = 1; i < n; i++)
    {
      if (A[i] % 2 == 0)
        return i;
    }
    if (on_n == 0)
      return n;
    else
      return n+1;
  }
};

