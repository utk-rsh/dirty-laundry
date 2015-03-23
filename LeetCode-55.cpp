#include <iostream>

using namespace std;

class Solution {
public:
    bool canJump(int A[], int n)
    {
      int jumps = A[0];
      int index = 0;
      while (index < n-1)
      {
        if (jumps == 0)
          return false;
        jumps--;
        index++;
        jumps = max(jumps, A[index]);
      }
      return true;
    }
};
