#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int trap(int A[], int n)
    {
        int temp_water = 0;
        int total_water = 0;
        int current_water = 0;
        int height = A[0];
        int temp_height = 0;
        int index_tall = 0;
        for (int i = 0; i < n; i++)
        {
          temp_height = A[i];
          if (height > temp_height)
          {
            temp_water += height - temp_height;
          }
          else if (height <= temp_height)
          {
            total_water += temp_water;
            temp_water = 0;
            height = A[i];
            index_tall = i;
          }
          //cout << "i " << i << " temp_water " << temp_water << " total_water " << total_water << "  height " << height << endl;
        }
        temp_water = 0;
        height = A[n-1];
        for (int i = n - 1; i >= index_tall; i--)
        {
          temp_height = A[i];
          if (height > temp_height)
          {
            temp_water += height - temp_height;
          }
          else if (height <= temp_height)
          {
            total_water += temp_water;
            temp_water = 0;
            height = A[i];
          }
        }
        return total_water;
    }
};

int main()
{
  Solution obj;
  int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
  int n = 12;
  int ans = obj.trap(A, n);
  cout << "Ans is " << ans << endl;
  return 0;
}
