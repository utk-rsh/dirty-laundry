#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int> &height)
  {
    int low = 0;
    int high = height.size() - 1;
    int area = 0;
    while (low <= high)
    {
      area = max(area, min(height[low], height[high])*(high-low+1));
      if (height[low] < height[high])
        low++;
      else
        high--;
    }
    return area;
  }
};
