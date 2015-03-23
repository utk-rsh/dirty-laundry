#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n)
    {
      int max_sum = A[0];
      int sum = 0;
      int all_negative = 1;
      int largest = A[0];
      for (int i = 0; i < n; i++)
      {
        sum += A[i];
        if (A[i] >= 0)
          all_negative = 0;
        if (sum < 0)
          sum = 0;
        largest = max(A[i], largest);
        max_sum = max(max_sum, sum);
      }
      if (all_negative)
        return largest;
      return max_sum;
    }
};
