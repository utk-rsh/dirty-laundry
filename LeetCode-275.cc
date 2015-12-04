class Solution {
public:
  int hIndex(vector<int>& citations) 
  {
    if (citations.size() == 0)
      return 0;
    int low = 0;
    int high = citations.size() - 1;
    while (low != high)
    {
      int mid = low + (high - low)/2;
      if (citations.size() - mid <= citations[mid])
        high = mid;
      else
        low = mid + 1;
    }
    if (citations[low] == 0)
      return 0;
    return (citations.size() - low);      
  }
};