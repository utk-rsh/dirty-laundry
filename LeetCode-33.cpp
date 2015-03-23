#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(int A[], int n, int target)
    {
      int low = 0;
      int high = n-1;
      if (A[low] == target)
        return low;
      if (A[high] == target)
        return high;
      while (high - low > 1)
      {
        int mid = (low + high)/2;
   //     cout << "low: " << low << "  mid: " << mid << "  high: " << high << endl;
        if (A[mid] == target)
          return mid;
        if (A[low] == target)
          return low;
        if (A[high] == target)
          return high;
        else if (A[mid] > A[low])
        {
          if (target > A[mid])
            low = mid + 1;
          else
          {
            if (target > A[low])
              high = mid - 1;
            else
              low = mid + 1;
          }
        }
        else if (A[mid] < A[low])
        {
          if (target > A[mid])
          {
            if (target < A[high])
              low = mid + 1;
            else
              high  = mid - 1;
          }
          if (target < A[mid])
            high = mid - 1;
        }
      }
      if (A[low] == target)
        return low;
      if (A[high] == target)
        return high;
      return -1;
    }
};
